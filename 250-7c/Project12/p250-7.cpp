#include <stdio.h>

int main() {
	int num,k;
	int a=1;
	printf("상수 n입력 : ");
	scanf_s("%d", &num);
	for (int i = 1;; i++) {
		a *= 2;
		if (a > num) {
			k = i-1;
			break;
		}
	}
	printf("\n공식을 만족하는 k의 최댓값은 %d", k);
	return 0;
}