#ifndef MOVE_H
#define MOVE_H

#include <vector>
#include<iostream>
class Move{
public:
    void move(int stepA, int stepB);//方塊移動
    void Transform();//方塊轉向
    bool Stop();//結束遊戲
    int point();//獲得加分
    bool Judge();//判斷方塊是否可以變換樣式

private:
    int x, y; // 座標
    int FG;//變化型別
};



#endif
