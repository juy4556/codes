#include <stdio.h>
#include <stdlib.h>
/* ���ڿ� �Է� �޾Ƽ� �Է� ���� ���ڿ��� �ܾ ������ ����ϴ� ���α׷�
 ��, ���ڿ��� �Է¿� �ռ� ���α׷� ����ڰ� �Է��� ���ڿ��� �ִ���� ������ ���� �Է� �ޱ�*/
char* ReadString(int n) {
	char* ptr = (char*)calloc(1,n);
	printf("���ڿ� �Է�: ");
	gets(ptr);
	return ptr;
}

int main() {
	int num;
	int i, j,k;
	char* str;
	printf("���ڿ��� �ִ���� �Է�: ");
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