#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
	float num = 0;
	int sign = 0;
	int square = 0; //정규화과정에서 발생하는 지수를 받기위한 변수
	int bias;
	int mantissa[23] = { 0 };

	printf("Plz real number: ");
	scanf("%f", &num);

	if (num < 0) {
		sign = 1;
		num = -num;
	} //부호 설정 양수=0, 음수=1

	while (num >= 2.0) //입력받은 num이 정수일 경우 1<=num<2의 범위로만들기 and 지수 증가
	{
		num /= 2;
		square++;
	}
	while (num < 1.0) //입력받은 num이 소수일 경우 1<=num<2의 범위로만들기 and 지수 감소
	{
		num *= 2;
		square--;
	}

	bias = 127 + square;

	num -= 1.0; //가수를 구하기 위해 소수로 변경

	for (int k = 0; k < 23; k++) //소수부분 이진수로 변환
	{
		num *= 2;
		if (num >= 1) {
			mantissa[k] = 1;
			num -= 1;
		}
		else {
			mantissa[k] = 0;
		}
	}

	printf("%d.", sign); //부호에 따른 0 or 1 출력

	for (int i = 7; i >= 0; i--)//지수부분출력
	{
		printf("%d", (bias >> i) & 1);
	}
	printf(".");

	for (int j = 0; j < 23; j++) //가수부분 출력
	{
		printf("%d", mantissa[j]);
	}

	return 0;
}
