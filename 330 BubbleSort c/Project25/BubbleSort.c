#include <stdio.h>

DesSort(int* ary) {
	int i, j,temp;
	for (i = 0; i < 7; i++) {
		for (j = 0; j < 7 - i; j++) {
			if (ary[j] < ary[j + 1]) {
				temp = ary[j];
				ary[j] = ary[j + 1];
				ary[j + 1] = temp;
			}
		}
	}
}
int main() {
	int arr[7];
	for (int i = 0; i < 7; i++) {
		printf("ют╥б: ");
		scanf_s("%d", &arr[i]);
	}
	DesSort(arr);
	for (int i = 0; i < 7; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
}