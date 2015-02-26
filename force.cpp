#include <iostream>
#include <vector>
#include <windows.h>
#include<conio.h>
#include <time.h> 

#define ARRIBA 72
#define ABAJO 80
#define IZQUIERDA 75
#define DERECHA 77

#define P2_UP 87
#define P2_DOWN 83
#define P2_RIGHT 68
#define P2_LEFT 65

int interval = 200;

using namespace std;

void gotoxy(int x, int y);

void DrawPaddle(int cX, int cY){
	for (int i = 0; i < 7; i++)
	{
		gotoxy(cX, cY+i);
		cout << "#";
	}
}

void DrawBall(int cX, int cY){
		gotoxy(cX, cY);
		cout << "O";
}

float ball_dir_x = -1;
float ball_dir_y = 0;
float ballSpeed = 1;
int ballX = 25;
int ballY = 15;

void updateBall(){

	gotoxy(ballX, ballY);
	cout << " ";

	ballX += ball_dir_x * ballSpeed;
	ballY += ball_dir_y * ballSpeed;
	DrawBall(ballX, ballY);
}

void ResetBall(){
	ballX = 25;
	ballY = 15;
}

int main(){
	srand(time(NULL));
	int P1X = 1;
	int P1Y = 10;

	int P2X = 50;
	int P2Y = 10;


	DrawPaddle(P1X, P1Y);
	DrawPaddle(P2X, P2Y);

	bool game_over = false;

	while (!game_over)
	{
		// cout << endl;
		// cout<<"P1 " << P1X << " " << P1Y << endl;
		// cout << "P2 " << P2X << " " << P2Y << endl;
		// cout <<"Ball " << ballX << " " << ballY << endl;
		Sleep(interval);
		updateBall();

		//check collision
		if (ballX == (P1X+1) && (ballY >= P1Y && ballY <= P1Y+7)){
			ball_dir_x *= -1;
		}

		if (ballX == (P2X-1) && (ballY >= P2Y && ballY <= P2Y + 7)){
			ball_dir_x *= -1;
		}

		if (ballX <= 0 || ballY <= 0)
			ResetBall();
		if (ballX >= 50 || ballY <= 0)
			ResetBall();
		
		if (kbhit())
		{
			int key = getch();
			gotoxy(P1X, P1Y);
			printf(" ");

			if (key == ARRIBA)
			{
				system("cls");
				P1Y--;
				gotoxy(P1X, P1Y);
				DrawPaddle(P1X, P1Y);
				DrawPaddle(P2X, P2Y);
			}
			if (key == ABAJO)
			{
				P1Y++;
				gotoxy(P1X, P1Y);
				DrawPaddle(P1X, P1Y);
				DrawPaddle(P2X, P2Y);
			}
			if (key == IZQUIERDA)
			{
				P1X--;
				gotoxy(P1X, P1Y);
				DrawPaddle(P1X, P1Y);
				DrawPaddle(P2X, P2Y);
			}
			if (key == DERECHA)
			{
				P1X++;
				gotoxy(P1X, P1Y);
				DrawPaddle(P1X, P1Y);
				DrawPaddle(P2X, P2Y);
			}

			if (key == P2_UP)
			{
				system("cls");
				P2Y--;
				gotoxy(P2X, P2Y);
				DrawPaddle(P1X, P1Y);
				DrawPaddle(P2X, P2Y);
			}
			if (key == P2_DOWN)
			{
				P2Y++;
				gotoxy(P2X, P2Y);
				DrawPaddle(P1X, P1Y);
				DrawPaddle(P2X, P2Y);
			}
			if (key == P2_LEFT)
			{
				P2X--;
				gotoxy(P2X, P2Y);
				DrawPaddle(P1X, P1Y);
				DrawPaddle(P2X, P2Y);
			}
			if (key == P2_RIGHT)
			{
				P2X++;
				gotoxy(P2X, P2Y);
				DrawPaddle(P1X, P1Y);
				DrawPaddle(P2X, P2Y);
			}
		}


		}

	cout << endl;
	return 0;
}

void gotoxy(int x, int y)
{

	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hCon, dwPos);

}