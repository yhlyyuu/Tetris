#ifndef BLOCK_H
#define BLOCK_H

#include "Move.h"
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;

enum piece_type {         //���������
    t_piece,
    i_piece,
    o_piece,
    l_piece,
    j_piece,
    s_piece,
    z_piece
};

enum move_direction {   //���ʤ�V
    rightO = 1,
    leftO = -1
};
class Block {
private:
    vector<Move> body;//�U�Ӥ���椸����m
    Move pos;//�������e��m
    piece_type type;

public:
    Block();
    Block(Move pos);//��l�Ƥ������m
    void fall_down();//����V�U����(��s�������m)
    vector<Move> next_fall_down_body();//������V���ʤ@��
    void move(move_direction dir);//����b���w��V�W���ʤ@��
    vector<Move> next_move_body(move_direction dir);//����b���w��V�W���ʤ@��᪺��m
    void rotate();//�������
    vector<Move> next_rotate_body();//����i�����ާ@�᪺��m

    vector<Move> get_body() { return body; }//��^�������m
    void set_body(vector<Move> b) { body = b; }//�]�w�������m
};


#endif
