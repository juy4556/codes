#include <stdio.h>

int main() {
	int num = -1;
	int x;//정수형 변수 선언
	scanf_s("%d", &x);//x입력
	
	switch (x) {
	case -1:
		num--;
		break;
	case 1:
		num--;
		break;
	default:
		num = 0;
		break;
	}
	printf("x:%d\n", x);
	printf("num:%d", num);
	return 0;
}