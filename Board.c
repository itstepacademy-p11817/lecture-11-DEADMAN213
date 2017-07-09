#include <conio.h>
#include <stdio.h>

int main() {
	int num = 8;
	//-1 - серая клетка, 0 - белая
	int board[8][8] = { { 0,  0, -1,  0, -1,  0,  0,  0},
						{ 0, -1,  0,  0, -1, -1,  0,  0},
						{-1, -1,  0, -1,  0,  0,  0, -1},
						{-1, -1,  0,  0,  0,  0,  0,  0},
						{ 0, -1,  0,  0,  0, -1,  0,  0},
						{ 0, -1,  0, -1, -1,  0, -1, -1},
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
		int cellWeight = 0;
		for (int i = 0; i < num; i++)
			for (int j = 0; j < num; ) {
				if (board[i][j] == 0) {
					cellWeight = 0;
					int ind = j;
					while (ind < num && board[i][ind] == 0) {//от текущего j до первой серой клетки или конца строки
						cellWeight++;
						ind++;
					}

					board[i][j] = cellWeight;//первой белой клетке ряда присваиваем её вес
					for (ind = j + 1; ind < j + cellWeight; ind++)//каждой последующей клетке белого ряда присваиваем её вес
						board[i][ind] = board[i][ind - 1] - 1;
				}

				//определяем слудующий j
				if (cellWeight == 0)
					j++;
				else {
					j += cellWeight;
					cellWeight = 0;
				}
			}
	}

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
						if ((board[ind + 1][j] < 0 || cellsLine > board[ind + 1][j]) && curSquare > square) {
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