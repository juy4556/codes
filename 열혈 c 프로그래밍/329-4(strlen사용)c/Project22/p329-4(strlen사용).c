#include <stdio.h>
#include <string.h>

int main() {
	char arr[20];
	printf("���ڿ� �Է�: ");
	gets_s(arr,20);
	int len = strlen(arr);
	for (int i = 0; i < len / 2; i++) {
		if (arr[i] != arr[len - 1 - i]) {
			printf("ȸ���� �ƴմϴ�.");
			return 1;
		}
	}
	printf("ȸ���Դϴ�.");
	return 0;
}