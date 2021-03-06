#include <stdio.h>
int StrLen(char* str) {
	int cnt=0;
	while (str[cnt] != 0) {
		cnt++;
	}
	return cnt;
}
int main() {
	char arr[20];
	int len;
	printf("문자열 입력: ");
	gets(arr);
	len = StrLen(arr);
	for (int i = 0; i < len / 2; i++) {
		if (arr[i] != arr[len-1-i]) {
			printf("Not palindrome");
			return 1;
		}
	}
	printf("회문입니다");
	return 0;
}