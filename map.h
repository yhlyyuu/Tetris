
#ifndef TETRISMAP_H
#define TETRISMAP_H

const int MAP_WIDTH = 10;
const int MAP_HEIGHT = 20;

class TetrisMap {
private:
    char map[MAP_HEIGHT][MAP_WIDTH];

public:
    TetrisMap();
    void clearMap();
    bool isCollision(int x, int y);
    void placePiece(int x, int y, char piece);
    void printMap();
};

#endif
