#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Game.h"
#include "Map.h"
using namespace std;


Game::Game(int r, int c) {
	row = r;
	col = c;
	score = 0;
	level = 1;
	map = vector<vector<int>>(row, vector<int>(col, 0));
}

void Game::start() {
	Map map;
	// 隨機生成一個方塊
	currentBlock = Block::createRandomBlock();
	// 遊戲主循環
	while (true) {
		system("cls");
		map.printMap();
		printScore();
		printLevel();
		// 當前方塊自由下落
		



		// 將當前方塊加入地圖
		updateMap();
		map.printMap();
		updateScore();
		updateLevel();
		
		if (gameOver()) {
			cout << "Game over! " << endl;
			break;
		}
		// 隨機生成一個方塊
		currentBlock = Block::createRandomBlock();
	}
}

bool Game::gameOver() {
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
	int line = 0;
	for (int i = 0; i < row; i++) {
		bool flag = true;
		for (int j = 0; j < col; j++) {
			if (map[i][j] == 0) {
				flag = false;
				break;
			}
		}
		if (flag) {
			line++;
			map.erase(map.begin() + i);
			map.insert(map.begin(), vector<int>(col, 0));
		}
	}
	switch (line) {
	case 1:
		score += 10;
		break;
	case 2:
		score += 30;
		break;
	case 3:
		score += 50;
		break;
	case 4:
		score += 80;
		break;
	default:
		break;
	}
}

void Game::updateLevel() {
	level = score / 100 + 1;
}

void Game::printScore() {
	cout << "Score: " << score << endl;
}

void Game::printLevel() {
	cout << "Level: " << level << endl;
}