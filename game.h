
#ifndef GAME_H
#define GAME_H

#define N 3
#define EMPTY 0

#define SCREEN_HEIGHT 480
#define SCREEN_WIDTH 640


#define PLAYER_X 1
#define PLAYER_O 2

#define CELL_WIDTH  ( SCREEN_WIDTH  / N )
#define CELL_HEIGHT ( SCREEN_HEIGHT / N )


#define RUNNING_STATE 0
#define PLAYER_X_WON_STATE 1
#define PLAYER_0_WON_STATE 2
#define TIE_STATE 3
#define QUIT_STATE 4


struct Game_t{
    int board[N * N];
    int player;
    int state;
};


#endif // GAME_H
