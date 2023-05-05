#ifndef BLOCK_H
#define BLOCK_H

#include <vector>
#include<iostream>
using namespace std;
class Block {
private:
    enum Type { I, J, L, O, S, T, Z };
    Type t;
    vector<vector<int>> shape; // 方塊形狀，用二維矩陣表示
    int x, y; 
public:
    Block();
    Block(Type t1, int x1, int y1); 
    vector<vector<int>> getShape();
    int getX();
    int getY();
    static Block createRandomBlock(); // 創建隨機方塊
   
};

#endif
