#include <stdio.h>
int main() {
	int num = 0;
	int sum = 0;
	do {
		sum += num;
		num += 2;
	} while (num <= 100);
	printf("SUM:%d", sum);
}