//p423 #21-1 getchar�Լ��� putchar�Լ��� Ȱ��
#include <stdio.h>

int main() {
	int ch = getchar();
	if (ch >= 65 && ch <= 90)
		 putchar(ch + 32);
	else if (ch >= 90 && ch <= 115)
		putchar(ch - 32);
	else
		printf("���ĺ� ġ��� �Ѥ�");
	return 0;
}