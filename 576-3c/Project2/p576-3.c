#include <stdio.h>
#define MAX(A,B) (A)>(B) ? (A) : (B)

int main() {
	int a, b;
	scanf_s("%d %d", &a, &b);
	printf("둘 중 더 큰 값은 %d\n", MAX(a, b));
	return 0;
}