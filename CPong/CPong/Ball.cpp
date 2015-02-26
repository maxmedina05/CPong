#include "Ball.h"


Ball::Ball()
{
	resetBall();
}


Ball::~Ball()
{
}

void Ball::setSpeed(int speed){
	_speed = speed;
}

int Ball::getSpeed(){
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

}

void Ball::resetBall(){
	_position = Vector2D(25, 15);
	_direction = Vector2D(-1, 0);
	_speed = 1;
}