#include <stdio.h>
void ShowAllArr(int j,int (*ptr)[4]) {
	int i;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			printf("%2d ", ptr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int main() {
	int arr[4][4];
	int i, j;
	int n = 1;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			arr[i][j] = n;
			n++;
		}
	}
	ShowAllArr(sizeof(arr[0])/sizeof(int),arr);
	n = 1;
	for (i = 3; i >= 0; i--) {
		for (j = 0; j < 4; j++) {
			arr[j][i] = n;
			n++;
		}
	}
	ShowAllArr(sizeof(arr[0])/sizeof(int),arr);
	n = 1;
	for (i = 3; i >= 0; i--) {
		for (j = 3; j >= 0; j--) {
			arr[i][j] = n;
			n++;
		}
	}
	ShowAllArr(sizeof(arr[0]) / sizeof(int), arr);
	n = 1;
	for (i = 0; i < 4; i++) {
		for (j = 3; j >= 0; j--) {
			arr[j][i] = n;
			n++;
		}
	}
	ShowAllArr(sizeof(arr[0]) / sizeof(int), arr);
	return 0;
}