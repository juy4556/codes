#include <stdio.h>

int main() {
	int binary, tmp;
	int c, exit = 1;
	while (exit == 1) {
		printf("������ �Է� :");
		scanf_s("%d", &tmp);//ex)10
		printf("������ : ");
		for (c = 7; c >= 0; c--) {
			binary = tmp >> c;
			if (binary & 1) 
				printf("1");
			else 
				printf("0");//result ex)000001010
		}
		printf("\n��� 1, ���� 0 :");
		scanf_s("%d", &exit);
		printf("\n");
	}
	return 0;
}