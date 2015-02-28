#include "ConsoleHandler.h"


ConsoleHandler::ConsoleHandler()
{
}


ConsoleHandler::~ConsoleHandler()
{
}

void ConsoleHandler::DrawGameScene(){

}

void ConsoleHandler::DrawPaddle(Paddle paddle){

	for (int i = 0; i < paddle.getLength(); i++){
		Vector2D pos = paddle.getPosition();
		pos.setY(pos.getY() + i);
		gotoXY(pos);
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
	pos.X = (int)position.getX();
	pos.Y = (int)position.getY();
	SetConsoleCursorPosition(handle, pos);
}

void ConsoleHandler::DrawCText(Vector2D position, string Text){
	gotoXY(position);
	cout << Text;
}