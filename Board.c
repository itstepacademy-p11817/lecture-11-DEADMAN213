#include <conio.h>
#include <stdio.h>

int main() {
	int num = 8;
	//-1 - серая клетка, 0 - белая
	int board[8][8] = { { 0,  0, -1,  0, -1,  0,  0,  0},
						{ 0,  0, -1,  0,  0, -1,  0,  0},
						{-1, -1,  0, -1,  0,  0,  0, -1},
						{-1, -1,  0,  0,  0,  0,  0,  0},
						{ 0, -1,  0,  0,  0, -1,  0,  0},
						{ 0, -1,  0, -1, -1,  0,  0, -1},
						{ 0,  0,  0,  0,  0,  0,  0,  0},
						{ 0,  0, -1,  0,  0, -1,  0, -1} };

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++)
			printf("%3d", board[i][j]);
		printf("\n");
	}
	printf("\n");

	{
		//Определение веса каждой клетки
		for (int i = 0; i < num; i++)
			for (int j = num - 1; j >= 0; ) {
				int ind = j - 1;
				if (board[i][j] == 0) {
					board[i][j] = 1;
					while (ind >= 0 && board[i][ind] == 0) {//от текущего j до первой серой клетки или конца строки
						board[i][ind] = board[i][ind + 1] + 1;
						ind--;
					}
				}

				//определяем слудующий j
				if (ind == j - 1)
					j--;
				else 
					j = ind - 1;
			}//for (int j = num - 1; j >= 0; )
	}

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++)
			printf("%3d", board[i][j]);
		printf("\n");
	}
	printf("\n");

	{
		//Вычисление площади прямоугольников
		int topLeft[2] = { -1, -1 };
		int bottomRight[2] = { -1, -1 };
		int square = 0;
		for (int i = 0; i < num; i++)
			for (int j = 0; j < num; j++)
				if (board[i][j] > 0) {//если клетка белая
					int cellsLine = board[i][j];//присваиваем её вес
					int ind = i;
					while (ind < num && board[ind][j] > 0) {//пока не конец столбца и клетка не серая
						int curSquare = cellsLine*(ind - i + 1);
						if ((board[ind + 1][j] < 0 || cellsLine > board[ind + 1][j] || ind >= num - 1) && curSquare > square) {
							square = curSquare;
							topLeft[0] = i;
							topLeft[1] = j;
							bottomRight[0] = ind;
							bottomRight[1] = j + cellsLine - 1;
						}
						ind++;
						if (cellsLine > board[ind][j] && board[ind][j] > 0)
							cellsLine = board[ind][j];
					}
				}//if (board[i][j] > 0)
		printf("[%d, %d] - [%d, %d]: %d.\n", topLeft[0] + 1, topLeft[1] + 1, bottomRight[0] + 1, bottomRight[1] + 1, square);
	}

	_getch();

	return 0;
}