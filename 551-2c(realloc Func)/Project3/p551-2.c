#include <stdio.h>
#include <stdlib.h>

int main() {
	int arrlen = 5;
	int *arr = (int*)malloc(sizeof(int) * arrlen);
	int i;
	int end;

	for (i = 0;; i++) {
		if (arrlen==i) {
			arrlen += 3;
			arr = (int*)realloc(arr, sizeof(int) * arrlen);
		}
		scanf_s("%d", &arr[i]);
		if (arr[i] == -1) {
			end = i;
			break;
		}
	}
	for (int i = 0; i < end; i++) {
		printf("%d ", arr[i]);
	}
	free(arr);
	return 0;
}