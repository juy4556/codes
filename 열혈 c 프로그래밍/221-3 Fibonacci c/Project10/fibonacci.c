#include <stdio.h>
void Fiboseq(int n) {
	int f1 = 0, f2 = 1,f3,i;
	if (n == 1)
		printf("%d\n", f1);
	else {
		printf("%d, %d", f1, f2);
		for (i = 0; i < n - 2; i++) {
			f3 = f1 + f2;
			printf(", %d", f3);
			f1 = f2;
			f2 = f3;
		}
	}
}
int main() {
	int num;
	printf("몇번째까지 출력할래\n");
	scanf_s("%d", &num);
	if (num < 1) {
		printf("양의 정수를 입력해\n");
		return -1;
	}
	printf("옛다!\n");
	Fiboseq(num);
	return 0;
}