#include <stdio.h>

int main() {
	int i, j;
	int n;
	int num = 1;
	printf("양의 정수 입력 : ");
	scanf_s("%d", &n);
	int arr[30][30] = {0};
	for (int k = n; k >= 1; k--) {
		for (i = n-k; i < k; i++) {//row up
			arr[n - k][i] = num;
			num++;
		}
		for (j = n-(k-1); j < k; j++) {//column up
			arr[j][k-1] = num;
			num++;
		}
		for (i = k - 2; i >= n-k; i--) {//row down
			arr[k - 1][i] = num;
			num++;
		}
		for (j = k - 2; j >= n - (k - 1); j--) {//column down
			arr[j][n - k] = num;
			num++;
		}
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%-3d ", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}