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
	printf("���°���� ����ҷ�\n");
	scanf_s("%d", &num);
	if (num < 1) {
		printf("���� ������ �Է���\n");
		return -1;
	}
	printf("����!\n");
	Fiboseq(num);
	return 0;
}