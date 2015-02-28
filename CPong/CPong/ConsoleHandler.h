#include <iostream>
#include <string>
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
	int _height;
	Vector2D _center;


public:
	ConsoleHandler();
	ConsoleHandler(int width, int height, Vector2D center) : _width(width), _height(height), _center(center) {}
	~ConsoleHandler();
	
	void setWidth(int );
	int getWidth();
	void setHeight(int );
	int getHeight();
	void setCenter(Vector2D);
	Vector2D getCenter();

	void DrawGameScene();
	void DrawPaddle(Paddle paddle);
	void DrawBall(Ball);
	void DrawWhiteSpace(Vector2D);
	void gotoXY(Vector2D);
	void DrawCText(Vector2D position, string Text);
};

