#include<conio.h>
#include <math.h>
#include <time.h> 
#include "Ball.h"
#include "Paddle.h"
#include "Vector2D.h"
#include "Player.h"
#include "ConsoleHandler.h"

#define INTERVAL 100

#define P1_UP 72
#define P1_DOWN 80

//#define P2_UP 87
//#define P2_DOWN 83
#define P2_UP 'w'
#define P2_DOWN 's'
#pragma once
class GameController
{
private:
	bool _gameOver;
	Player _player01;
	Player _player02;
	ConsoleHandler _cHandler;

	Ball _ball;

public:
	GameController();
	~GameController();

	void gameLoop();
	void gameInit();

	void setPlayer01(Player player);
	void setPlayer02(Player player);
	void setConsoleHandler(ConsoleHandler handler);
	void setBall(Ball ball);
	void CheckBallCollision();
	void BallOutOfGameScene();
	static float RamdomFloat(float a, float b);
};

