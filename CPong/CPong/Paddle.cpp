#include "Paddle.h"


Paddle::Paddle()
{
}


Paddle::~Paddle()
{
}

void Paddle::setPosition(Vector2D position){
	_position = position;
}

Vector2D Paddle::getPosition(){
	return _position;
}