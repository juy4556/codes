#include <stdio.h>

int main() {
	int arr1[10];
	int arr2[10];
	int cnt[10] = { 0 };
	int i, j;
	int sum = 0;
	for (i = 0; i < 10; i++) {
		scanf_s("%d", &arr1[i]);
	}
	for (i = 0; i < 10; i++) {
		arr2[i] = arr1[i] % 42;
	}
	for (i = 0; i < 10; i++) {
		for (j = i + 1; j < 10; j++) {
			if (arr2[i] == arr2[j])
				cnt[i]++;
		}
		if (cnt[i] > 1)
			cnt[i] = 1;
	}
	for (i = 0; i < 9; i++) {
		sum += cnt[i];
	}
	printf("서로 다른 수의 갯수: %d", 10 - sum);
	return 0;
}