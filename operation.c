#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#include"My_Fraction.h"

int main() {
	char input[100];

	printf("Please enter the fraction calculation (Available characters:+,-,*,/): ");
	fgets(input, sizeof(input), stdin);

	int n1, d1, n2, d2;
	char c;
	sscanf(input, "%d/%d %c %d/%d", &n1, &d1, &c, &n2, &d2);

	my_fraction fra1 = create(n1,d1);
	my_fraction fra2 = create(n2, d2);
	my_fraction result=0;

	switch (c) {
	case'+':
		result = add(fra1, fra2);
		break;
	case'-':
		result = minus(fra1, fra2);
		break;
	case'*':
		result = mult(fra1, fra2);
		break;
	case'/':
		result = divid(fra1, fra2);
		break;
	default:
		printf("operator error!");
		return 1;
	}

	print(result);

	return 0;
}
