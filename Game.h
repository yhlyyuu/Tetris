#ifndef GAME_H
#define GAME_H

#include <vector>
#include "Block.h"
using namespace std;
class Game {
public:
    Game(int row = 20, int col = 10);  // 篶硑ㄧ计
    void start();  // 秨﹍笴栏
private:
    int row;  // ︽计
    int col;  // 计
    int score;  // だ计
    int level;  // 单
    vector<vector<int>> map;  // 瓜
    Block currentBlock;  // 讽玡よ遏
    bool isGameOver();  // 耞笴栏琌挡
    void updateMap();  // 穝瓜
    void updateScore();  // 穝だ计
    void updateLevel();  // 穝单
    void printMap();  // ゴ瓜
    void printScore();  // ゴだ计
    void printLevel();  // ゴ单
};

#endif
