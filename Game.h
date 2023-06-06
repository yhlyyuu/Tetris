#ifndef GAME_H
#define GAME_H


#include <iostream>
#include <vector>
#include <algorithm>
#include "windows.h"

#include "Move.h"
#include "Block.h"
#include "Board.h"

class Game {
private:
    Board board;
    Block curr_piece;
    std::vector<Move> final_pionts;
    int score;
    int speed;
    bool run;
public:

    Game();
    void controls();
    void running();
    bool hit_built_points_down();

    bool checked_move(enum move_direction dir);
    bool checked_rotate();

    void draw();
    void refresh_final_points();

    void ClearScreen();
    bool game_over();
    bool regame();


};


#endif