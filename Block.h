#ifndef BOARD_H
#define BOARD_H

#include "Block.h"
#include <vector>
#include <algorithm>
using namespace std;
class Board {
private:
    int width;
    int height;
    vector<Move> all_points;
    vector<Move> built_points;
public:
    Board(int width = 30, int height = 30);

    int get_width() { return width; }
    int get_height() { return height; }
    vector<Move> get_all_points() { return all_points; }
    vector<Move> get_built_points() { return built_points; }
    void set_built_points(vector<Move> built_points) { this->built_points = built_points; }
    void set_border();

    void insert_to_built_points(vector<Move> insert_points);
    int remove_row();
    void refresh();

};

#endif
