#ifndef GAME_H
#define GAME_H

#include <vector>
#include "Block.h"
using namespace std;
class Game {
public:
    Game(int row = 20, int col = 10);  // �c�y���
    void start();  // �}�l�C��
private:
    int row;  // ���
    int col;  // �C��
    int score;  // ����
    int level;  // ����
    vector<vector<int>> map;  // �a��
    Block currentBlock;  // ��e���
    bool isGameOver();  // �P�_�C���O�_����
    void updateMap();  // ��s�a��
    void updateScore();  // ��s����
    void updateLevel();  // ��s����
    void printMap();  // ���L�a��
    void printScore();  // ���L����
    void printLevel();  // ���L����
};

#endif
