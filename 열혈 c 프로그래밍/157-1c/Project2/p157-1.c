#include <stdio.h>

int main() {
	int num;
	int i = 0;
	int sum = 0;
	while (i < 5) {
		scanf_s("%d", &num);
		while (num <= 0) {
			printf("���� ������ �Է��ض� �ڽľ�!");
			scanf_s("%d", &num);
		}
		i++;
		sum += num;
	}
	printf("SUM : %d", sum);
	return 0;
}