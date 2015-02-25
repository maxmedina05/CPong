#pragma once
class Vector2D
{
private:
	int _x;
	int _y;
public:


	Vector2D();
	~Vector2D();
	Vector2D(int x, int y) : _x(x), _y(y){}

	void setX(int x){ _x = x; }
	int getX(){ return _x; }

	void setY(int y){ _y = y; }
	int getY(){ return _y; }

};

