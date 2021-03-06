//p423 #21-1 getchar함수와 putchar함수의 활용
#include <stdio.h>

int main() {
	int ch = getchar();
	if (ch >= 65 && ch <= 90)
		 putchar(ch + 32);
	else if (ch >= 90 && ch <= 115)
		putchar(ch - 32);
	else
		printf("알파벳 치라고 ㅡㅡ");
	return 0;
}