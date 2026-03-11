#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	double x = 0;
	short bit = 0;

	printf("Plz enter real number: ");
	if (scanf("%lf", &x) != 1) {
		printf("error!");
		return 1;
	}

	bit = (short)(x * 256);

	for (int i = 15;i >= 0;i--) {
		printf("%d", (bit >> i) & 1);
		if (i == 8) {
			printf(".");
		}
	}

	return 0;
}
