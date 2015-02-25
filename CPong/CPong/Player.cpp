#include "Player.h"


Player::Player()
{
}


Player::~Player()
{
}

void Player::setName(string name){
	_name = name;
}
string Player::getName(){
	return _name;
}

void Player::setScore(int score){
	_score = score;
}

int Player::getScore(){
	return _score;
}