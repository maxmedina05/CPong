#pragma once
class Vector2D
{
public:
	int X;
	int Y;

	Vector2D();
	~Vector2D();
	Vector2D(int x, int y) : X(x), Y(y){}
};

