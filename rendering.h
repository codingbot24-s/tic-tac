
#include "game.h"
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_render.h>

#ifndef RENDERING_H

#define RENDERING_H

void render_game(SDL_Renderer* renderer, const Game_t* game);
void render_game_over(SDL_Renderer* renderer, const Game_t* game,SDL_Color);

#endif // RENDERING_H
