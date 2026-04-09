#include<stdio.h>

int fibo(int n) {
	if (n <=0 ) return 0;

	if (n ==1 ) return 1;

	int result;
	int temp1 = 1;
	int temp2=0;

	for (int i = 2; i <= n;i++) {
		result = temp1 + temp2;
		temp2 = temp1;
		temp1 = result;
	}

	return result;
}

int main() {
	int N = 0;

	printf("숫자를 입력하세요: ");
	scanf_s("%d", &N);

	int fn = fibo(N);

	printf("%d", fn);

	return 0;
}
