#include "ConsoleHandler.h"


ConsoleHandler::ConsoleHandler()
{
}


ConsoleHandler::~ConsoleHandler()
{
}

void ConsoleHandler::DrawGameScene(){}

void ConsoleHandler::DrawPaddle(Paddle paddle){

	for (int i = 0; i < paddle.getLength(); i++){
		gotoXY(paddle.getPosition());
		cout << "#";
	}
}

void ConsoleHandler::DrawBall(Ball ball){
	gotoXY(ball.getPosition());
	cout << "O";
}

void ConsoleHandler::DrawWhiteSpace(Vector2D position){
	gotoXY(position);
	cout << " ";
}

void ConsoleHandler::gotoXY(Vector2D position){
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = position.getX();
	pos.Y = position.getY();
	SetConsoleCursorPosition(handle, pos);
}