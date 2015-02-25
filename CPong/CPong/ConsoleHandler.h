#include <windows.h>

#pragma once
class ConsoleHandler
{

private:
	int _width;
	int _heigth;

public:
	ConsoleHandler();
	~ConsoleHandler();


	void DrawGameScene();

};

