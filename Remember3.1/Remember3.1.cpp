#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <iostream>
#include <ctime>
using namespace std;
int** arr;
int** board;
int s1, s2;
bool flag = true;
int numberOfCard = 0;
HANDLE hconsole;

void fillArr(int* arr[], int s1, int s2);
void createArr(int difficult);
void printBoard(int* arr[], int s1, int s2);
void replacement(int x, int y, int* numbers[], int* board[], int mode);
void Coordinate(int* mass[], int* mass2[], int s1, int s2);
void checkWin(int* board[], int s1, int s2);

int main() {
	int fa;
	cout << "\t\tMember GAME\n";
	cout << "*1 - board 4x2\n";
	cout << "**2 - board 4x4\n";
	cout << "***3 - board 6x4\n";
	cout << "chose mode of difficult:\n";
	cin >> fa;

	createArr(fa);
	printBoard(board, s1, s2);


	int start = clock();


	while (flag) {
		Coordinate(arr, board, s1, s2);
		printBoard(board, s1, s2);
		checkWin(board, s1, s2);
	}
	system("cls");
	cout << endl << "\t\tYOU WIN!!!\n\n";

	int end = clock();
	int t = (end - start) / CLOCKS_PER_SEC;
	cout << endl << "Time of game";
	cout << endl << "  Minutes: " << t / 60 << endl;
	cout << "  Seconds: " << t % 60;
	cout << endl << "Steps: " << numberOfCard;

}
//Проверка окончания игры
void checkWin(int* board[], int s1, int s2) {
	int count = 0;
	for (int i = 0; i < s1; i++) {
		for (int j = 0; j < s2; j++) {
			if (board[i][j] != 0) count++;
		}
	}
	if (count == s1 * s2) flag = false;
}

//Вывод доски
void printBoard(int* arr[], int s1, int s2) {
	system("cls");
	cout << "    ";
	//Координаты
	for (int i = 0; i < s2; i++) {
		cout << i << "  ";
	}
	cout << endl;
	cout << "                          ";
	for (int i = 0; i < s1; i++) {
		cout << endl << i << " | "; //координаты
		for (int j = 0; j < s2; j++) {
			cout << arr[i][j] << "  ";
		}
	}
}
//Замена между массивами (открытие карт)
void replacement(int x, int y, int* arr[], int* board[], int mode) {
	if (mode == 1) {
		board[x][y] = arr[x][y];
	}
	else if (mode == 2) {
		board[x][y] = 0;
	}
}

void Coordinate(int* mass[], int* mass2[], int s1, int s2) {
	int x1, y1, x2, y2;
	bool flag2 = true;
	// Цикл для проверки верности ввода координат
	//Ввод координат
	while (flag2) {
		cout << endl << "Enter first coordinates x1,y1" << endl;
		cin >> x1 >> y1;
		//Проверка провекра проверка
		if (x1 >= s1 or y1 >= s2 or x1 < 0 or y1 < 0
			or board[x1][y1] != 0) {
			cout << "WRONG";
			Sleep(1000);
			system("cls");
			printBoard(board, s1, s2);
			continue;
		}
		replacement(x1, y1, mass, mass2, 1);
		printBoard(board, s1, s2);
		cout << endl << "Enter second coordinates x2,y2" << endl;
		cin >> x2 >> y2;
		if (x2 >= s1 or y2 >= s2 or x2 < 0 or y2 < 0) {
			cout << "WRONG";
			Sleep(1000);
			system("cls");
			printBoard(board, s1, s2);
			continue;
		}
		else flag2 = false;
		replacement(x2, y2, mass, mass2, 1);
		printBoard(board, s1, s2);

		if (x1 == x2 and y1 == y2) {
			cout << "WRONG";
			Sleep(1000);
			system("cls");
			replacement(x1, y1, mass, mass2, 2);
			replacement(x2, y2, mass, mass2, 2);
			printBoard(board, s1, s2);
			continue;
		}
	}
	if (x1 != x2 or y1 != y2) {
		if (mass[x1][y1] == mass[x2][y2]) {
			numberOfCard += 2;

			Beep(233, 100); Sleep(125);
			Beep(294, 100); Sleep(125);
			Beep(349, 100); Sleep(125);
			Beep(466, 100); Sleep(125);
			Beep(587, 100); Sleep(125);
			Beep(698, 100); Sleep(125);
			Beep(932, 100); Sleep(575);
			Beep(932, 100); Sleep(125);
			Beep(932, 100); Sleep(125);
			Beep(932, 100); Sleep(125);
			Beep(1046, 100);
		}


		else {
			numberOfCard += 2;
			replacement(x1, y1, mass, mass2, 2);
			replacement(x2, y2, mass, mass2, 2);
			float B = 493.88,
				D = 587.32,
				A = 440.00,
				G = 392.00;

			Beep(B, 300);
			Beep(D, 300);
			Beep(B, 300);
			Beep(D, 600);

			Beep(B, 300);
			Beep(A, 300);
			Beep(B, 600);

			Beep(A, 300);
			Beep(G, 300);
			Beep(A, 600);
			Beep(G, 600);
		}
	}
	Sleep(1000);
}

//Созданием массива
void createArr(int difficult) {
	//Создаём двумерный массив в зависимости от избранной сложности
	srand(time(NULL));
	if (difficult == 3) {
		s1 = 6;
		s2 = 4;
		arr = new int* [s1];
		for (int i = 0; i < s1; i++) {
			arr[i] = new int[s2];
		}

		//Массив "визуальной" доски
		board = new int* [s1];

		for (int i = 0; i < s1; i++) {
			board[i] = new int[s2];
		}

		for (int i = 0; i < s1; i++) {
			for (int j = 0; j < s2; j++) {
				board[i][j] = 0;
			}
		}



	}

	else if (difficult == 2) {
		s1 = 4;
		s2 = 4;
		arr = new int* [s1];
		for (int i = 0; i < s1; i++) {
			arr[i] = new int[s2];
		}

		board = new int* [s1];

		for (int i = 0; i < s1; i++) {
			board[i] = new int[s2];
		}

		for (int i = 0; i < s1; i++) {
			for (int j = 0; j < s2; j++) {
				board[i][j] = 0;
			}
		}
	}

	else if (difficult == 1) {
		s1 = 4;
		s2 = 2;
		arr = new int* [s1];
		for (int i = 0; i < s1; i++) {
			arr[i] = new int[s2];
		}

		board = new int* [s1];

		for (int i = 0; i < s1; i++) {
			board[i] = new int[s2];
		}

		for (int i = 0; i < s1; i++) {
			for (int j = 0; j < s2; j++) {
				board[i][j] = 0;
			}
		}
	}

	fillArr(arr, s1, s2);
}
//Заполнение массива случайными числами
void fillArr(int* arr[], int s1, int s2) {
	srand(time(NULL));
	// 1 часть массива
	for (int n, i = 0; i < s1 / 2; i++) {
		for (int j = 0; j < s2; j++) {

			bool ok;

			do {
				ok = true;
				n = rand() % (s1 * s2 / 2) + 1;
				for (int l = 0; l < s1 / 2; l++) {
					for (int g = 0; g < s2; g++) {
						if (arr[l][g] == n) { ok = false; break; }
					}
				}
			} while (!ok);
			arr[i][j] = n;

		}
	}
	// 2 часть массива
	for (int n, i = s1 / 2; i < s1; i++) {
		for (int j = 0; j < s2; j++) {

			bool ok;

			do {
				ok = true;
				n = rand() % (s1 * s2 / 2) + 1;
				for (int l = s1 / 2; l < s1; l++) {
					for (int g = 0; g < s2; g++) {
						if (arr[l][g] == n) { ok = false; break; }
					}
				}
			} while (!ok);
			arr[i][j] = n;

		}
	}

}
