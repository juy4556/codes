#include <stdio.h>
#include <stdlib.h>
/* 문자열 입력 받아서 입력 받은 문자열의 단어를 역으로 출력하는 프로그램
 단, 문자열의 입력에 앞서 프로그램 사용자가 입력할 문자열의 최대길이 정보를 먼저 입력 받기*/
char* ReadString(int n) {
	char* ptr = (char*)calloc(1,n);
	printf("문자열 입력: ");
	gets(ptr);
	return ptr;
}

int main() {
	int num;
	int i, j,k;
	char* str;
	printf("문자열의 최대길이 입력: ");
	scanf_s("%d", &num);
	while (getchar() != '\n');
	str = ReadString(num);
	for (i = num-1;i>=0; i--) {
		if (str[i] == ' ') {
			for (j = i+1; str[j]>=33 && str[j]<=126; j++) {
				printf("%c", str[j]);
			}
			printf(" ");
		}
		if (i == 0) {
			for (k = 0; str[k] != ' '; k++)
				printf("%c", str[k]);
		}
	}

	free(str);
	return 0;
}