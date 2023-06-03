#ifndef BLOCK_H
#define BLOCK_H

#include "Move.h"
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;

enum piece_type {         //方塊的種類
    t_piece,
    i_piece,
    o_piece,
    l_piece,
    j_piece,
    s_piece,
    z_piece
};

enum move_direction {   //移動方向
    rightO = 1,
    leftO = -1
};
class Block {
private:
    vector<Move> body;//各個方塊單元的位置
    Move pos;//方塊的當前位置
    piece_type type;

public:
    Block();
    Block(Move pos);//初始化方塊的位置
    void fall_down();//方塊向下移動(更新方塊的位置)
    vector<Move> next_fall_down_body();//垂直方向移動一格
    void move(move_direction dir);//方塊在指定方向上移動一格
    vector<Move> next_move_body(move_direction dir);//方塊在指定方向上移動一格後的位置
    void rotate();//方塊旋轉
    vector<Move> next_rotate_body();//方塊進行旋轉操作後的位置

    vector<Move> get_body() { return body; }//返回方塊的位置
    void set_body(vector<Move> b) { body = b; }//設定方塊的位置
};


#endif
