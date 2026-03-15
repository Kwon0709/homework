#include<stdio.h>

int main() {
	char str[100];

	printf("String input: ");
	fgets(str, sizeof(str), stdin);//입력

	int i = 0;

	while (str[i] !='\0') //입력된 문장이 끝날때까지 반복
		{
		if (str[i] >= 'A' && str[i] <= 'Z') {
			str[i] = str[i] + 32; //대문자일 경우 소문자로 전환
		}
		else if(str[i]>='a'&&str[i]<='z'){
			str[i] = str[i] - 32; // 소문자일 경우 대문자로 전환
		}
		i++;
	}
		
	printf("Converted string: %s", str); //출력

	return 0;
}
