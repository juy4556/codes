#include <stdio.h>

int main() {
	int num,k;
	int a=1;
	printf("��� n�Է� : ");
	scanf_s("%d", &num);
	for (int i = 1;; i++) {
		a *= 2;
		if (a > num) {
			k = i-1;
			break;
		}
	}
	printf("\n������ �����ϴ� k�� �ִ��� %d", k);
	return 0;
}