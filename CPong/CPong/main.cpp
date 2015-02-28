#include <iostream>
#include <vector>
#include <windows.h>

#include "GameController.h"

int main(){
	GameController controller;

	controller.gameInit();
	controller.gameLoop();

	cout << endl << endl;

	return 0;
}