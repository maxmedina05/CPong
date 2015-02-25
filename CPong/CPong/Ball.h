#include "Vector2D.h"

#pragma once
class Ball
{
private:
	int _speed;
	Vector2D _direction;
	Vector2D _position;
public:
	Ball();
	~Ball();

	void setSpeed(int speed);
	int getSpeed();
	void setDirection(Vector2D direction);
	Vector2D getDirection();
	void setPosition(Vector2D position);
	Vector2D getPosition();
};

