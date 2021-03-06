#include <stdio.h>

int main() {
	int n;
	printf("0이상의 정수 입력 : ");
	scanf_s("%d", &n);
	switch (n / 10) {
	case 0:
		printf("0이상 10미만 수");
		break;
	case 1:
		printf("10이상 20미만 수");
		break;
	case 2:
		printf("20이상 30미만의 수");
		break;
	default:
		printf("30이상의 수");
	}
}