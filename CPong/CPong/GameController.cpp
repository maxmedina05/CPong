#include "GameController.h"

GameController::GameController(){
}


GameController::~GameController(){
}


void GameController::gameInit(){
	_gameOver = false;
}

void GameController::gameLoop(){
	while (_gameOver){

		Sleep(INTERVAL);
	}
}
