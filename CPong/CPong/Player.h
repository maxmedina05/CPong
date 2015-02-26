#include <string>
#include "Paddle.h"
using namespace std;

#pragma once
class Player
{
private:
	string _name;
	int _score;
	Paddle _paddle;

public:
	Player();
	~Player();

	void setName(string name);
	string getName();

	void setScore(int score);
	int getScore();

	void setPaddle(Paddle paddle){ _paddle = paddle; }
	Paddle getPaddle(){ return _paddle; }
};

