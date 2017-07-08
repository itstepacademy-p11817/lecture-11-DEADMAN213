#include <conio.h>
#include <stdio.h>
#include <math.h>

int main() {
	int x = 0;
	int y = 0;
	int compint = 1;
	double compdoub = 1.0;

	printf("Input x: ");
	scanf_s("%d", &x);

	printf("Input y: ");
	scanf_s("%d", &y);

	if (y >= 0) {
		for (int i = 0; i < y; i++)
			compint *= x;
		printf("%d^%d = %d", x, y, compint);
	}
	else {
		for (int i = 0; i < abs(y); i++)
			compdoub /= x;
		printf("%d^%d = %.2f", x, y, compdoub);
	}
	
	_getch();
	return 0;
}