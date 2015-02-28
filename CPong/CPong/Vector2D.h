#pragma once
class Vector2D
{
private:
	float _x;
	float _y;
public:


	Vector2D();
	~Vector2D();
	Vector2D(float x, float y) : _x(x), _y(y){}

	void setX(float x){ _x = x; }
	float getX(){ return _x; }

	void setY(float y){ _y = y; }
	float getY(){ return _y; }

};

