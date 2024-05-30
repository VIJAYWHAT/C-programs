#include <stdio.h>

int main()
{
	int i, space, n = 5, j = 0;

	for (i = 0; i < n - 1; i++) {

		for (space = 1; space < n - i; space++) {
			printf(" ");
		}
		for (j = 0; j <= 2 * i; j++) {
			if (j == 0 || j == 2 * i)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
	for (i = 0; i < 2 * n - 1; i++) {
		printf("*");
	}
	return 0;
}
