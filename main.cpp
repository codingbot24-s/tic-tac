
#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <cstddef>
#include <cstdio>

#include "game.h"
#include "logic.h"
#include "rendering.h"

int main()
{
  if (SDL_Init(SDL_INIT_VIDEO) != 0)
  {
    fprintf(stderr, "sdl init failed\n");
    return -1;
  }
  SDL_Window *win = SDL_CreateWindow("tic tac toe", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
  if (win == NULL)
  {
    fprintf(stderr, "cant create the window");
    return -1;
  }

  SDL_Renderer *renderer = SDL_CreateRenderer(win, -1, 0);
  if (renderer == NULL)
  {
    SDL_DestroyWindow(win);
    fprintf(stderr, "cant create the renderer\n");
    return -1;
  }

  Game_t game = {
      .board = {
          EMPTY,
          EMPTY,
          EMPTY,
          EMPTY,
          EMPTY,
          EMPTY,
          EMPTY,
          EMPTY,
          EMPTY,
      },
      .player = PLAYER_X,
      .state = RUNNING_STATE,
  };

  SDL_Event e;
  while (game.state != QUIT_STATE)
  {
    while (SDL_PollEvent(&e))
    {
      switch (e.type)
      {
      case SDL_QUIT:
        game.state = QUIT_STATE;
        break;
      case SDL_MOUSEBUTTONDOWN:
        click_cell(game, e.button.y / CELL_HEIGHT, e.button.x / CELL_WIDTH);
        break;
      default:
      {
      }
      }
    }
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    render_game(renderer, &game);
    SDL_RenderPresent(renderer);
  }

  SDL_DestroyWindow(win);
  SDL_Quit();

  return -1;
}
