#include "Vector2D.h"

#pragma once
class Ball
{
private:
	float _speed;
	Vector2D _direction;
	Vector2D _position;
public:
	Ball();
	~Ball();

	void setSpeed(float speed);
	float getSpeed();
	void setDirection(Vector2D direction);
	Vector2D getDirection();
	void setPosition(Vector2D position);
	Vector2D getPosition();

	void updateBall();
	void resetBall();
};

