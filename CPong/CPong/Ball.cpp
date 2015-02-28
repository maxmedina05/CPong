#include "Ball.h"


Ball::Ball()
{
	resetBall();
}


Ball::~Ball()
{
}

void Ball::setSpeed(float speed){
	_speed = speed;
}

float Ball::getSpeed(){
	return _speed;
}

void Ball::setDirection(Vector2D direction){
	_direction = direction;
}
Vector2D Ball::getDirection(){
	return _direction;
}
void Ball::setPosition(Vector2D position){
	_position = position;
}

Vector2D Ball::getPosition(){
	return _position;
}

void Ball::updateBall(){
	_position = Vector2D((int) (_position.getX() + _direction.getX()*_speed), (int)(_position.getY() + _direction.getY()*_speed));
}

void Ball::resetBall(){
	_position = Vector2D(25, 15);
	_direction = Vector2D(-1, 0);
	_speed = 1;
}