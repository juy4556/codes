#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int i;
	srand((int) time(NULL));
	for (i = 1; i <= 2; i++) {
		printf("�ֻ��� %d�� ��� : %d\n", i, rand() % 7);
	}
	return 0;
}