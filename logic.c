


#include "game.h"
#include <SDL2/SDL_render.h>

void player_turn(struct Game_t* game,int row,int column)
{

}

void reset_game() 
{

}

void click_cell(struct Game_t* game, int row, int column)
{
    if (game->state == RUNNING_STATE)
    {
        player_turn(game,row,column);
    }else {
        reset_game();
    }
    
}
void render_running_state (SDL_Renderer *renderer, const struct Game_t* game);
