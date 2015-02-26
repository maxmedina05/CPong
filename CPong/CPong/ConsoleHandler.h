#include <iostream>
#include <windows.h>
#include "Vector2D.h"
#include "Paddle.h"
#include "Ball.h"

using namespace std;

#pragma once
class ConsoleHandler
{

private:
	int _width;
	int _heigth;
	Vector2D _center;


public:
	ConsoleHandler();
	~ConsoleHandler();
	
	void setWidth(int );
	int getWidth();
	void setHeigth(int );
	int getHeigth();
	void setCenter(Vector2D);
	Vector2D getCenter();

	void DrawGameScene();
	void DrawPaddle(Paddle paddle);
	void DrawBall(Ball);
	void DrawWhiteSpace(Vector2D);
	void gotoXY(Vector2D);
};

