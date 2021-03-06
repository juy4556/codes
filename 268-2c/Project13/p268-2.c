#include <stdio.h>
int main() {
	char arr[50];
	int len=0;
	char temp;
	gets(arr);
	for (int i = 0; arr[i] != 0; i++) {
		len = i;
	}
	for (int j = 0; j < len-1; j++) {
		temp = arr[j];
		arr[j] = arr[len - j];
		arr[len - j] = temp;
	}
	printf("%s", arr);
	return 0;
}