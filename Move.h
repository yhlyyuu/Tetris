#ifndef MOVE_H
#define MOVE_H

#include <vector>
#include<iostream>
class Move{
public:
    void move(int stepA, int stepB);//�������
    void Transform();//�����V
    bool Stop();//�����C��
    int point();//��o�[��
    bool Judge();//�P�_����O�_�i�H�ܴ��˦�

private:
    int x, y; // �y��
    int FG;//�ܤƫ��O
};



#endif
