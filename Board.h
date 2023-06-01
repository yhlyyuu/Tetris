#if !defined(PIECE_H_)
#define PIECE_H_

#include "Move.h"
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;
enum piece_type {
    t_piece,
    i_piece,
    o_piece,
    l_piece,
    j_piece,
    s_piece,
    z_piece
};

enum move_direction {
    rightO = 1,
    leftO = -1
};

class Block {
private:
    enum piece_type type;
    vector<Move> body;
    Move pos;


public:
    Block() = default;
    Block(Move pos);
    void fall_down();
    vector<Move> next_fall_down_body();
    void move(enum move_direction dir);
    vector<Move> next_move_body(enum move_direction dir);
    void rotate();
    vector<Move> next_rotate_body();

    vector<Move> get_body() { return body; }
    void set_body(vector<Move> body) { this->body = body; }

};

#endif
