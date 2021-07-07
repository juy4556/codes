#include <stdio.h>
void DecimalToBinary(int num) {
	if (num == 1) {
		return printf("%d",num);
	}
		DecimalToBinary(num/2);
		printf("%d", num % 2);
}
int main() {
	int num;
	printf("양의 정수 ㄱ");
	scanf_s("%d", &num);
	printf("\n이진법:");
	DecimalToBinary(num);

}