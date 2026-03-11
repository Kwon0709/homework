#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	double x = 0;
	short bit = 0;

	printf("Plz enter real number: "); //실수 입력

	if (scanf("%lf", &x) != 1) {
		printf("error!"); //실수를 정상적으로 입력 받지 못했을 경우 에러문구 띄우고 시스템 종료
		return 1;
	}

	if (x < -128 || x>127) {
		printf("Out of range!");//Q8.8범위에서 벗어날경우 범위에서 벗어남을 알려주고 시스템 종료
		return 1;
	}

	bit = (short)(x * 256);//실수를 고정소수점으로 변환

	for (int i = 15;i >= 0;i--) {
		printf("%d", (bit >> i) & 1);
		if (i == 8) {
			printf(".");
		}
	}

	return 0;
}
