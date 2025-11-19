#include "../src/async/async_stio.h"
#include "fcntl.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include "unistd.h"
#include "stdlib.h"
#include "time.h"

COROUTINE_DECL(server_background,
  int server_fd;
  struct sockaddr* server_addr;
  socklen_t server_len;
  ,
  int s;
)

COROUTINE_DECL(process_client,
  int client_fd;
  struct sockaddr* client_addr;
  socklen_t client_len;
  ,
  time_t timer;
)

COROUTINE_DECL(server_run,
  ,
  int server_fd;
  struct sockaddr_in server_addr;
  socklen_t server_len;
  int client_fd;
  struct sockaddr_storage client_addr;
  socklen_t client_len;
)

static int state = 1;

COROUTINE(server_background) {
  COROUTINE_INIT(server_background);
  while (state) {
    sleep(1);
    printf("Server Background Tasks!\n");
    COROUTINE_SAVEPOINT;
  }
  COROUTINE_EXIT;
}

static char buffer[4096];

COROUTINE(process_client) {
  COROUTINE_INIT(process_client);
  ((process_client_cr_state*)crt->static_state_data)->timer = time(NULL);
  while (state) {
    COROUTINE_SAVEPOINT;

    if (!state) {
      free(((process_client_cr_args*)crt->arg)->client_addr);
      COROUTINE_EXIT
    }

    if ((time(NULL) - ((process_client_cr_state*)crt->static_state_data)->timer) > 12) {
      close(((process_client_cr_args*)crt->arg)->client_fd);
      free(((process_client_cr_args*)crt->arg)->client_addr);
      printf("Client %d was timed-out!\n", ((process_client_cr_args*)crt->arg)->client_fd);
      COROUTINE_EXIT;
    }

    bzero(buffer, 1024);

    int n = read(((process_client_cr_args*)crt->arg)->client_fd, buffer, 1024);
    buffer[(n > 0) ? n : 0] = '\0';

    if (n < 1) {
      continue;
    }

    ((process_client_cr_state*)crt->static_state_data)->timer = time(NULL);

    printf("Connection with client established: read %d bytes:\n%s\n", n, buffer);

    sleep(1);

    if (!strncmp(buffer, ":q", 2)) {
      printf("':q' read\n");
      close(((process_client_cr_args*)crt->arg)->client_fd);
      free(((process_client_cr_args*)crt->arg)->client_addr);
      COROUTINE_EXIT;
    }

    if (!strncmp(buffer, ":sudo q -f", 10)) {
      state = 0;
      printf("':sudo q -f' read\n");
      close(((process_client_cr_args*)crt->arg)->client_fd);
      free(((process_client_cr_args*)crt->arg)->client_addr);
      COROUTINE_EXIT;
    }

    printf("Echoing back - %s", buffer);

    write(((process_client_cr_args*)crt->arg)->client_fd, buffer, n);

  }
}

int cnt;

COROUTINE(server_run, 512) {

  COROUTINE_INIT(server_run);

  ((server_run_cr_state*)crt->static_state_data)->server_fd = socket(AF_INET, SOCK_STREAM, 0);

  if (((server_run_cr_state*)crt->static_state_data)->server_fd < 0) {
    perror("Open socket");
  }

  bzero(&((server_run_cr_state*)crt->static_state_data)->server_addr, sizeof(((server_run_cr_state*)crt->static_state_data)->server_addr));

  ((server_run_cr_state*)crt->static_state_data)->server_addr.sin_family = AF_INET;
  ((server_run_cr_state*)crt->static_state_data)->server_addr.sin_addr.s_addr = htons(INADDR_ANY);
  ((server_run_cr_state*)crt->static_state_data)->server_addr.sin_port = htons(22000);

  bind(((server_run_cr_state*)crt->static_state_data)->server_fd, (struct sockaddr *) &((server_run_cr_state*)crt->static_state_data)->server_addr, sizeof(((server_run_cr_state*)crt->static_state_data)->server_addr));

  if (listen(((server_run_cr_state*)crt->static_state_data)->server_fd, 100)) {
    perror("Listen failed");
  }

  int flags = fcntl(((server_run_cr_state*)crt->static_state_data)->server_fd, F_GETFL, 0); // Get current flags

  if (flags == -1) {
      perror("fcntl F_GETFL");
      // Handle error
  }

  if (fcntl(((server_run_cr_state*)crt->static_state_data)->server_fd, F_SETFL, flags | O_NONBLOCK) == -1) { // Set O_NONBLOCK flag
      perror("fcntl F_SETFL O_NONBLOCK");
      // Handle error
  }
  
  COROUTINE_ASYNC_CALL(server_background, \
                       {.server_addr=(struct sockaddr *)&((server_run_cr_state*)crt->static_state_data)->server_addr, \
                        .server_fd=((server_run_cr_state*)crt->static_state_data)->server_fd, \
                        .server_len=sizeof(((server_run_cr_state*)crt->static_state_data)->server_addr)})

  while (state) {

    sleep(1);

    printf("LOG: %d\n", cnt++);

    ((server_run_cr_state*)crt->static_state_data)->client_fd = accept(((server_run_cr_state*)crt->static_state_data)->server_fd, (struct sockaddr *)&((server_run_cr_state*)crt->static_state_data)->client_addr, &((server_run_cr_state*)crt->static_state_data)->client_len);

    if (((server_run_cr_state*)crt->static_state_data)->client_fd == -1) {
      if (errno == EAGAIN || errno == EWOULDBLOCK) {
        // No pending connections, continue with other tasks or wait using select/poll/epoll
        // printf("No pending connections, trying again later...\n");
        // printf("No connections to accept!\n");
      } else {
        perror("accept");
        // Handle other accept errors
      }
    } else {
      // A new client connection has been accepted, handle it
      printf("Accepted new connection on socket %d\n", ((server_run_cr_state*)crt->static_state_data)->client_fd);
      // You might want to set this new client_sock_fd to non-blocking as well
      fcntl(((server_run_cr_state*)crt->static_state_data)->client_fd, F_SETFL, fcntl(((server_run_cr_state*)crt->static_state_data)->client_fd, F_GETFL, 0) | O_NONBLOCK);

      struct sockaddr* client_addr = malloc(((server_run_cr_state*)crt->static_state_data)->client_len);
      memcpy(client_addr, &((server_run_cr_state*)crt->static_state_data)->client_addr, ((server_run_cr_state*)crt->static_state_data)->client_len);

      COROUTINE_ASYNC_CALL(process_client, \
                           {.client_addr=client_addr, \
                            .client_fd=((server_run_cr_state*)crt->static_state_data)->client_fd, \
                            .client_len=((server_run_cr_state*)crt->static_state_data)->client_len});

      printf("Coroutine Added! - %d\n", __async_handler__.cr_list_size);
    }

    COROUTINE_SAVEPOINT;

  }

  close(((server_run_cr_state*)crt->static_state_data)->server_fd);

  COROUTINE_EXIT;
}

int main() {

  COROUTINE_ADD(server_run, {});

  COROUTINE_RUN;

  return 0;
  
}
