#include "Block.h"
#include <vector>
using namespace std;
Block::Block() {
    x = 0;
    y = 0;
    t = I;
    shape = vector<vector<int>>(4, vector<int>(4, 0));
}

Block::Block(Type t1, int x1, int y1) {
    t = t1;
    x = x1;
    y = y1;
    switch (t) {
    case I:
        shape = { {1,1,1,1} };
        break;
    case J:
        shape = { {0,0,1},
                  {1,1,1} };
        break;
    case L:
        shape = { {1,0,0},
                  {1,1,1} };
        break;
    case O:
        shape = { {1,1},
                  {1,1} };
        break;
    case S:
        shape = { {0,1,1},
                  {1,1,0} };
        break;
    case T:
        shape = { {0,1,0},
                  {1,1,1} };
        break;
    case Z:
        shape = { {1,1,0},
                  {0,1,1} };
        break;
    }
}

vector<vector<int>>Block::getShape() {
    return shape;
}

int Block::getX() {
    return x;
}

int Block::getY() {
    return y;
}

Block Block::createRandomBlock() {
    //隨機創建一個方塊
   
    Type randomType = static_cast<Type>(rand() % 7);

    int randomX = 0; 
    int randomY = 0; 

    return Block(randomType, randomX, randomY);
}


