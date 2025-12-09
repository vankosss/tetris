
#include <iostream>
#include <conio.h>
#include <ctime>
#include <windows.h>

const int gamezone_hight = 20;
const int gamezone_widght = 12;

int gamezone[gamezone_hight][gamezone_widght]; // 0 - пусто, 1 - блок, 9 - стена/пол

int x, y;

void Setup() {

	for (int i = 0; i < gamezone_hight; i++) {
		for (int j = 0; j < gamezone_widght; j++) {
			if (j == 0 || j == gamezone_widght - 1 || i == gamezone_hight - 1) {
				gamezone[i][j] = 9;
			}
			else {
				gamezone[i][j] = 0;
			}
		}
	}

	x = gamezone_widght / 2;
	y = 0;

}

void Draw() {
	system("cls");

	for (int i = 0; i < gamezone_hight; i++) {
		for (int j = 0; j < gamezone_widght; j++) {

			if (i == y && j == x) {
				std::cout << "O";
			}

			else if (gamezone[i][j] == 0) {
				std::cout << " ";
			}

			else if (gamezone[i][j] == 9) {
				std::cout << "#";
			}

			else if (gamezone[i][j] == 1) {
				std::cout << "O";
			}
		}
		std::cout << std::endl; 
	}

}

void Logic() {

	if (gamezone[y + 1][x] == 0) {
		y++;
	}
	else {
		gamezone[y][x] = 1;

		for (int i = gamezone_hight - 2; i > 0; i--) {
			bool solid = true;
			for (int j = 1; j < gamezone_widght - 1; j++) {
				if (gamezone[i][j] == 0) {
					solid = false;
					break;
				}
			}

			if (solid) {
				for (int k = i; k > 0; k--) {
					for (int j = 1; j < gamezone_widght - 1; j++) {
						gamezone[k][j] = gamezone[k - 1][j];
					}
				}
				i++;
			}
		}

		x = gamezone_widght / 2;
		y = 0;
	}
}



void Input() {
	if (_kbhit()) {
		switch (_getch()) {
		case 'a':
			if (gamezone[y][x - 1] == 0) {
				x--;
			}
			break;
		case 'd': 
			if (gamezone[y][x + 1] == 0) {
				x++;
			}
			break;
		case 'x':
			exit(0);
			break;
		
			}
		
	}
}

int main()
{
	Setup();
	while (true) {
		Draw();
		Logic();
		Input();
		Sleep(100);
	}
	return 0;
}

