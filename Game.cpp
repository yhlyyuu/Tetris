#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Game.h"
using namespace std;

Game::Game(int r, int c) {
	row = r;
	col = c;
	score = 0;
	level = 1;
	map = vector<vector<int>>(row, vector<int>(col, 0));
}

void Game::start() {
	// �H���ͦ��@�Ӥ��
	srand(time(NULL));
	currentBlock = Block::createRandomBlock();
	// �C���D�`��
	while (true) {
		// ���L�a�ϡB���ơB����
		system("cls");
		printMap();
		printScore();
		printLevel();
		// ��e����ۥѤU��
		while (currentBlock.canMoveDown(map)) {
			currentBlock.moveDown();
			// ��s�a��
			updateMap();
			// ���L�a�ϡB���ơB����
			system("cls");
			printMap();
			printScore();
			printLevel();
		}
		// �N��e����[�J�a��
		updateMap();
		// ��s���ơB����
		updateScore();
		updateLevel();
		// �P�_�C���O�_����
		if (isGameOver()) {
			cout << "Game over!" << endl;
			break;
		}
		// �H���ͦ��@�Ӥ��
		currentBlock = Block::createRandomBlock();
	}
}

bool Game::isGameOver() {
	for (int j = 0; j < col; j++) {
		if (map[0][j] == 1) {
			return true;
		}
	}
	return false;
}

void Game::updateMap() {
	for (int i = 0; i < currentBlock.getShape().size(); i++) {
		for (int j = 0; j < currentBlock.getShape()[i].size(); j++) {
			if (currentBlock.getShape()[i][j] == 1) {
				map[currentBlock.getX() + i][currentBlock.getY() + j] = 1;
			}
		}
	}
}

void Game::updateScore() {
	int lines = 0;
	for (int i = 0; i < row; i++) {
		bool flag = true;
		for (int j = 0; j < col; j++) {
			if (map[i][j] == 0) {
				flag = false;
				break;
			}
		}
		if (flag) {
			lines++;
			map.erase(map.begin() + i);
			map.insert(map.begin(), vector<int>(col, 0));
		}
	}
	switch (lines) {
	case 1:
		score += 100;
		break;
	case 2:
		score += 300;
		break;
	case 3:
		score += 500;
		break;
	case 4:
		score += 800;
		break;
	default:
		break;
	}
}

void Game::updateLevel() {
	level = score / 1000 + 1;
}

void Game::printMap() {
	// �M�ū̹�
	system("cls");
	// ���L�a��
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (map[i][j] == 0) {
				cout << "��";
			}
			else if (map[i][j] == 1) {
				cout << "��";
			}
		}
		cout << endl;
	}
}

void Game::printScore() {
	cout << "Score: " << score << endl;
}

void Game::printLevel() {
	cout << "Level: " << level << endl;
}