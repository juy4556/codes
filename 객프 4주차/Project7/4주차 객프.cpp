#include <stdio.h>
int main() {
	int num1 = 10, num2 = 20, num3 = 30, num4 = 40;
	char arr2d[10][40];
	int i, j;

	int* whoA[4] = { &num1,&num2,&num3,&num4 };//whoA�� int�� ������ ������ �̷���� int�� ������ �迭 - |������ �迭|
	char(*whoB)[40] = arr2d;//whoB�� ���α��̰� 4��(sizeof(int) *4�� ũ������� �����Ϳ��� �� ���� ���� �� �����ϴ�)int�� 2���� �迭�� ����Ű�� �뵵�� ������ ���� - |�迭 ������(����)|
	//���������� �Ұ�ȣ�� ���� whoA�� �迭 ����, whoB�� ������ ���� ����
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