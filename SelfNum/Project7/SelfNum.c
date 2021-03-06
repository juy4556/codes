#include <stdio.h>
#include <stdlib.h>

int main() {
	int i, j;
	int a, b, c, d, e;
	int* arr = (int*)calloc(10001, sizeof(int));
	for (i = 1; i <= 10000; i++) {
		for (j = 1; j <= i; j++) {
			a = j / 10000;
			b = j / 1000 - 10 * a;
			c = j / 100 - 10 * (10 * a + b);
			d = j / 10 - 10 * (100 * a + 10 * b + c);
			e = j - 10 * (1000 * a + 100 * b + 10 * c + d);
			if (i == 10001 * a + 1001 * b + 101 * c + 11 * d + 2*e)
				arr[i]++;
		}
		if (arr[i] == 0)
			printf("%d\n", i);
			}
	free(arr);
	return 0;
}