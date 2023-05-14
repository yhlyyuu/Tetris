#include "TetrisMap.h"
#include <iostream>

using namespace std;

TetrisMap::TetrisMap() {
    clearMap();
}

void TetrisMap::clearMap() {
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            map[i][j] = ' ';
        }
    }
}

bool TetrisMap::isCollision(int x, int y) {
 
    if (map[y][x] != ' ')
        return true;
    return false;
}

void TetrisMap::placePiece(int x, int y, char piece) {
    
    map[y][x] = piece;
}

void TetrisMap::printMap() {
    
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            cout << map[i][j] << ' ';
        }
        cout << endl;
    }
}
