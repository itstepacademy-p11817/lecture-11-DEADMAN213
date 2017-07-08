#include <conio.h>
#include <stdio.h>

int main() {
	int a = 0;
	int num = 500;
	int sum = 0;

	printf("Input a: ");
	scanf_s("%d", &a);

	for (int i = a; i <= 500; i++)
		sum += i;

	printf("Summ from %d to %d is %d.\n", a, num, sum);

	_getch();
	return 0;
}