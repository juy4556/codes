#include <stdio.h>

int main() {
	int arr[10];
	int num;
	int front = 0;
	int back = 9;
	for (int i = 0; i < 10; i++) {
		printf("�Է�: ");
		scanf_s("%d", &num);
		if (num % 2 != 0)
			arr[front++] = num;
		else
			arr[back--] = num;
	}
	printf("�迭 ����� ��� : ");
	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}

	return 0;
}