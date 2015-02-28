#include "GameController.h"
#include <conio.h>

GameController::GameController(){
}


GameController::~GameController(){
}


void GameController::gameInit(){
	_gameOver = false;

	Player player01;
	player01.setName("Player 01");
	player01.setScore(0);
	player01.setPaddle(Paddle(7, Vector2D(1, 10)));
	setPlayer01(player01);

	Player player02;
	player02.setName("Player 02");
	player02.setScore(0);
	player02.setPaddle(Paddle(7, Vector2D(50, 10)));
	setPlayer02(player02);

	Ball ball;
	ball.setDirection(Vector2D(1, 1));
	ball.setSpeed(1);
	ball.setPosition(Vector2D(25, 15));
	_ball = ball;

	_cHandler.DrawPaddle(player01.getPaddle());
	_cHandler.DrawPaddle(player02.getPaddle());

	_cHandler.DrawBall(_ball);
}

void GameController::gameLoop(){
	while (!_gameOver){
		
		//_cHandler.DrawCText(Vector2D(0, 0), to_string(_ball.getPosition().getX()) + " " + to_string(_ball.getPosition().getY()));
		_cHandler.DrawCText(Vector2D(0, 0), "Player 01: " + to_string(_player01.getScore()));
		_cHandler.DrawCText(Vector2D(0, 1), "Player 02: " + to_string(_player02.getScore()));
		Sleep(INTERVAL);

		if (kbhit()){
			int keyCode = getch();
			
			if (keyCode == P1_UP){
				system("cls");
				
				_player01.MoveUp();
				_cHandler.DrawPaddle(_player01.getPaddle());
				_cHandler.DrawPaddle(_player02.getPaddle());
				_cHandler.DrawBall(_ball);
			}

			if (keyCode == P1_DOWN){
				system("cls");

				_player01.MoveDown();
				_cHandler.DrawPaddle(_player01.getPaddle());
				_cHandler.DrawPaddle(_player02.getPaddle());
				_cHandler.DrawBall(_ball);
			}

			if (keyCode == P2_UP){
				system("cls");

				_player02.MoveUp();
				_cHandler.DrawPaddle(_player01.getPaddle());
				_cHandler.DrawPaddle(_player02.getPaddle());
				_cHandler.DrawBall(_ball);
			}

			if (keyCode == P2_DOWN){
				system("cls");

				_player02.MoveDown();
				_cHandler.DrawPaddle(_player01.getPaddle());
				_cHandler.DrawPaddle(_player02.getPaddle());
				_cHandler.DrawBall(_ball);
			}
		}

		BallOutOfGameScene();
		_cHandler.DrawWhiteSpace(_ball.getPosition());
		_ball.updateBall();
		_cHandler.DrawBall(_ball);
		CheckBallCollision();
	}
}

void GameController::setPlayer01(Player player){
	_player01 = player;
}
void GameController::setPlayer02(Player player){
	_player02 = player;
}
void GameController::setConsoleHandler(ConsoleHandler handler){
	_cHandler = handler;
}
void GameController::setBall(Ball ball){
	_ball = ball;
}

void GameController::BallOutOfGameScene(){
	Vector2D ballpos = _ball.getPosition();

	if (ballpos.getX() <= 0){
		_player01.AddPoint();
		_ball.resetBall();

		_ball.setDirection(Vector2D(1, RamdomFloat(-1, 1)));
	}

	if (ballpos.getX() > 49){
		_player02.AddPoint();
		_ball.resetBall();
		_ball.setDirection(Vector2D(-1, RamdomFloat(-1, 1)));
	}

}

void GameController::CheckBallCollision(){
	Vector2D ballposition = _ball.getPosition();
	Vector2D player01Pos = _player01.getPaddle().getPosition();
	Vector2D player02Pos = _player02.getPaddle().getPosition();

	if (ballposition.getX() == (player01Pos.getX() + 1) && 
		(ballposition.getY() >= player01Pos.getY() && ballposition.getY() <= player01Pos.getY() + _player01.getPaddle().getLength())){

		//_ball.setDirection(Vector2D(_ball.getDirection().getX() *-1, 0));
		_ball.setDirection(Vector2D(_ball.getDirection().getX() *-1, RamdomFloat(-1, 1)));
	}

	if (ballposition.getX() == (player02Pos.getX() - 1) &&
		(ballposition.getY() >= player02Pos.getY() && ballposition.getY() <= (player02Pos.getY() + _player02.getPaddle().getLength()) ) ){

		//_ball.setDirection(Vector2D(_ball.getDirection().getX() *-1, 0));
		_ball.setDirection(Vector2D(_ball.getDirection().getX() *-1, RamdomFloat(-1, 1)));
	}

	if (ballposition.getY() <= 5)
		_ball.setDirection(Vector2D(_ball.getDirection().getX(), 1));

	if (ballposition.getY() >= 20)
		_ball.setDirection(Vector2D(_ball.getDirection().getX(), -1));
}

float GameController::RamdomFloat(float a, float b){
	float random = ((float)rand()) / (float)RAND_MAX;
	float diff = b - a;
	float r = random * diff;
	return a + r;
}