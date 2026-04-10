#include<stdio.h>
#include<stdlib.h>

long long fibo(int n) {
	if (n <= 0) return 0;

	if (n == 1) return 1;

	long long result;
	long long temp1 = 1;
	long long temp2 = 0;

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

	long long fn = 0;
		fn=fibo(N);

	printf("%lld", fn);

	return 0;
}
