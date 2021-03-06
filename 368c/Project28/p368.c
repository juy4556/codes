#include <stdio.h>
void MaxandMin(int ary[],int size, int **max, int**min) {
	*max = &ary[0];
	*min = &ary[0];
	for (int i = 0; i < size-1; i++) {
		if (ary[i] < ary[i + 1]) {
			*max = &ary[i + 1];
		}
		if (ary[i] > ary[i + 1]) {
			*min = &ary[i + 1];
		}
	}
}
int main() {
	int* maxPtr;
	int* minPtr;
	int arr[5];
	for (int i = 0; i < 5; i++) {
		scanf_s("%d", &arr[i]);
	}
	MaxandMin(arr,sizeof(arr)/sizeof(int),&maxPtr, &minPtr);
	printf("MAX: %d, MIN: %d", *maxPtr, *minPtr);
	return 0;
}