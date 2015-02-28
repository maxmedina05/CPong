#include "Vector2D.h"

#pragma once
class Paddle
{
private:
	int _length;
	Vector2D _position;

public:
	Paddle();
	Paddle(int value) : _length(value){}
	Paddle(int value, Vector2D position) : _length(value), _position(position){}
	~Paddle();

	int getLength() { return _length; }
	void setPosition(Vector2D position);
	Vector2D getPosition();
	void MoveUp();
	void MoveDown();
};

