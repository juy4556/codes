#include <stdio.h>

int main() {
	int arr[10];
	int temp1, temp2, temp3;
	printf("총 10개의 숫자 입력\n");
	for (int i = 0; i < 10; i++) {
		printf("입력: ");
		scanf_s("%d", &arr[i]);
	}
	for (int j = 0; j < 10; j++) {
		for (int k = j; k < 10; k++) {
			if (arr[j] % 2 == 0 && arr[k] % 2 != 0) {
				temp1 = arr[j];
				arr[j] = arr[k];
				arr[k] = temp1;
			}
		}
	}
	for (int j = 0; j < 10; j++) {
		for (int k = 0; k < 10; k++) {
			if (arr[j] % 2 == 0 && arr[k] % 2 == 0) {
				if (arr[j] > arr[k]) {
					temp2 = arr[j];
					arr[j] = arr[k];
					arr[k] = temp2;
				}
			}
			else if(arr[j]%2!=0&&arr[k]%2!=0){
				if (arr[j] < arr[k]) {
					temp3 = arr[j];
					arr[j] = arr[k];
					arr[k] = temp3;
				}
			}
		}
	}
	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
}