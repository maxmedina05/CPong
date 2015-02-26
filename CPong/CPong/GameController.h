#include "Ball.h"
#include "Paddle.h"
#include "Vector2D.h"
#include "Player.h"
#include "ConsoleHandler.h"

#define INTERVAL 200

#pragma once
class GameController
{
private:
	bool _gameOver;
	Player _player01;
	Player _player02;

	Ball _ball;

public:
	GameController();
	~GameController();

	void gameLoop();
	void gameInit();
};

