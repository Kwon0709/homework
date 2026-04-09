#include<stdio.h>
#include<stdlib.h>
long long fibonacci(long long n) {

	if (n <= 2)  return 1;

	return fibonacci(n - 1) + fibonacci(n - 2);
}


int main() {
	long long N;

	printf("숫자를 입력해주세요: ");
	scanf_s("%lld", &N);

	long long fn = 0;
	
		fn = fibonacci(N);

		printf("%lld\n", fn);
	
	return 0;
}
