#pragma once
class Paddle
{
private:
	int _length;

public:
	Paddle();
	Paddle(int value) : _length(value){}
	~Paddle();

	int getLength() { return _length; }
};

