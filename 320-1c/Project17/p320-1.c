#include <stdio.h>

void SquareByValue(int n) {
	n *= n;
	printf("%d\n", n);
}
void SquareByReference(int* pn) {
	*pn *= *pn;
}
int main() {
	int num;
	scanf_s("%d", &num);
	SquareByValue(num);
	SquareByReference(&num);
	printf("%d", num);
	return 0;
}