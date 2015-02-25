#include <string>

using namespace std;

#pragma once
class Player
{
private:
	string _name;
	int _score;
public:
	Player();
	~Player();

	void setName(string name);
	string getName();

	void setScore(int score);
	int getScore();
};

