#include<stdio.h>

int main() {
	int x = 1; //임의의 정수값 설정

	if (~x == -x) {
		printf("This system is one's complement."); // NOT연산자를 사용하였을때 ~x와 -x 의 값이 같아지면 1의 보수
	}
	else if (~x + 1 == -x) {
		printf("This system is two's complement."); //NOT연산자를 사용하였을때 ~x의 값에 1을 더한값고 -x의 값이 같아진다면 2의 보수
	}

	return 0;
}
