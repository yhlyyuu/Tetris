#include "Move.h"


Move::Move(int x, int y, char type)
    :x{ x }, y{ y }, type{ type } {}

bool Move::operator==(const Move& rhs) const {
    return (x == rhs.get_x() && y == rhs.get_y());
}

Move Move::shift_copy(int x_shift, int y_shift) const {
    return Move(x + x_shift, y + y_shift, type);
}

void Move::move(int x_move, int y_move) {
    x += x_move;
    y += y_move;
}

void Move::set_coordinate(int x_new, int y_new) {
    x = x_new;
    y = y_new;
}
