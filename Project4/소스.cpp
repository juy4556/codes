#include <stdio.h>

int main() {
	int num = -1;
	int x;//������ ���� ����
	scanf_s("%d", &x);//x�Է�
	
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