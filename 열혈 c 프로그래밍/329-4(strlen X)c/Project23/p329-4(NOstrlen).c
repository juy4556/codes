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
	printf("���ڿ� �Է�: ");
	gets(arr);
	len = StrLen(arr);
	for (int i = 0; i < len / 2; i++) {
		if (arr[i] != arr[len-1-i]) {
			printf("Not palindrome");
			return 1;
		}
	}
	printf("ȸ���Դϴ�");
	return 0;
}