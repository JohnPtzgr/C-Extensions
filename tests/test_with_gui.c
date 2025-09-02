
#include "SDL2/SDL.h"
#include "../src/oop/class.h"
#include "../src/threads/task.h"


int MAIN_WINDOW_STATE = 0;

int main() {
  SDL_Init(SDL_INIT_EVERYTHING);
  SDL_Window* w = SDL_CreateWindow("Window!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 540, 540, 0);

  MAIN_WINDOW_STATE = 1;
  fd_set s;
  FD_ZERO(&s);

  int cnt = 0;

  SDL_Renderer* r = SDL_GetRenderer(w);

  SDL_SetRenderDrawColor(r, 0xaa, 0x00, 0xaa, 0);

  SDL_Rect rct = (SDL_Rect){.w = 100, .h = 100};

  SDL_RenderDrawRect(r, &rct);
  SDL_RenderFillRect(r, &rct);
  SDL_RenderPresent(r);

  while (MAIN_WINDOW_STATE)
  {
    FD_SET(0, &s);
    select(2, &s, NULL, NULL, &((struct timeval){.tv_sec=1}));
    MAIN_WINDOW_STATE = !(FD_ISSET(0, &s) || ((cnt++) > 10));
  }
  SDL_DestroyRenderer(r);
  SDL_DestroyWindow(w);
  SDL_Quit();
  
  return 0;
}