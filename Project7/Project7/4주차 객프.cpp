#include <stdio.h>
int main() {
	int num1 = 10, num2 = 20, num3 = 30, num4 = 40;
	char arr2d[10][40];
	int i, j;

	int* whoA[4] = { &num1,&num2,&num3,&num4 };//whoA는 int형 포인터 변수로 이루어진 int형 포인터 배열 - |포인터 배열|
	char(*whoB)[40] = arr2d;//whoB는 가로길이가 4인(sizeof(int) *4의 크기단위로 포인터연산 시 값이 증가 및 감소하는)int형 2차원 배열을 가리키는 용도의 포인터 변수 - |배열 포인터(변수)|
	//외형적으로 소괄호의 유무 whoA는 배열 선언, whoB는 포인터 변수 선언
	printf("%d %d %d %d \n", *whoA[0], *whoA[1], *whoA[2], *whoA[3]);
	for (i = 0; i < 10; i++) {
		gets_s(*whoB, 40);
		if (!(*whoB)[0])break;
	}

	for (i = 0; i < 10; i++) {
		for (j = 0; j < 40; j++) {
			printf("%c", (*whoB)[j]);
		}
		whoB++;
		printf("\n");
	}
	return 0;
}