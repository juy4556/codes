#include <stdio.h>
#include <string.h>

int main() {
	char arr[20];
	printf("문자열 입력: ");
	gets_s(arr,20);
	int len = strlen(arr);
	for (int i = 0; i < len / 2; i++) {
		if (arr[i] != arr[len - 1 - i]) {
			printf("회문이 아닙니다.");
			return 1;
		}
	}
	printf("회문입니다.");
	return 0;
}