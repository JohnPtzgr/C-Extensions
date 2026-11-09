#include "server.h"

#define PORT 8080
#define BACKLOG 3

#define __AS_STR_EXP(EXPR) __STRING(EXPR)

int main() {
  int client_fd;
  struct sockaddr_in client_addr;
  socklen_t client_len = sizeof(client_addr);
  char buffer[1024];
  socket_t* server_s = CLS(socket_t, AF_INET, SOCK_STREAM, 0, INADDR_ANY, PORT, AF_INET);
  
  // server_fd = socket(AF_INET, SOCK_STREAM, 0);
  // if (server_fd == -1) {
  //   perror("Ошибка создания сокета");
  //   exit(EXIT_FAILURE);
  // }
  // server_addr.sin_family = AF_INET;
  // server_addr.sin_addr.s_addr = INADDR_ANY;
  // server_addr.sin_port = htons(PORT);

  // if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
  //   close(server_fd);
  //   perror("Ошибка привязки");
  //   exit(EXIT_FAILURE);
  // }

  // if (listen(server_fd, BACKLOG) < 0) {
  //   close(server_fd);
  //   perror("Ошибка listen()");
  //   exit(EXIT_FAILURE);
  // }

  __AUX_CLS_VCLASS__(socket_t)->start(server_s, 0);
  __AUX_CLS_VCLASS__(socket_t)->listen(server_s, 0);

  printf("Сервер запущен на порту %d\n", PORT);

  int x = 0;

  while (x < 10) {
    // client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &client_len);
    
    __AUX_CLS_VCLASS__(socket_t)->accept(server_s, &client_fd, &client_addr, &client_len, 0);

    read(client_fd, buffer, sizeof(buffer) - 1);
    printf("Incoming request! %s\n", buffer);



    char response[] = "<html>Hello world</html>";
    char response_head[] = "HTTP/1.1 200 OK\r\n"
                           "Content-Type: text/html\r\n"
                           "Content-length: 25\r\n\r\n";
    write(client_fd, response_head, strlen(response_head));
    write(client_fd, response, strlen(response));
    char ip_str[INET_ADDRSTRLEN];
    if (client_addr.sin_family == AF_INET) {
      struct sockaddr_in *s = (struct sockaddr_in *)&client_addr;
      inet_ntop(AF_INET, &(s->sin_addr), ip_str, sizeof(ip_str));
    }
    printf("Responded to: (ip)%s, %d\n", ip_str, x);
    close(client_fd);
    x++;
  }

  __AUX_CLS_VCLASS__(socket_t)->stop(server_s);

  return 0;
}