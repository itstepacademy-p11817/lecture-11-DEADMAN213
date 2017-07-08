#include <conio.h>
#include <stdio.h>

int main() {
	int a = 0;
	int num = 20;
	long long comp = 1;

	do {
		printf("Input a: ");
		scanf_s("%d", &a);
	} while (a < 1 || a>20);

	for (int i = a; i <= 20; i++)
		comp *= i;

	printf("Composition of numerals form %d to %d is %lld.\n", a, num, comp);

	_getch();
	return 0;
}