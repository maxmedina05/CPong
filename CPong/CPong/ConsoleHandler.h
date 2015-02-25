#include <windows.h>
#include "Vector2D.h"
#include "Paddle.h"
#include "Ball.h"

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

	
	void DrawGameScene();
	void DrawPaddle(Paddle paddle);
};

