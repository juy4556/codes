#include <stdio.h>

int main() {
	int binary, tmp;
	int c, exit = 1;
	while (exit == 1) {
		printf("십진수 입력 :");
		scanf_s("%d", &tmp);//ex)10
		printf("이진수 : ");
		for (c = 7; c >= 0; c--) {
			binary = tmp >> c;
			if (binary & 1) 
				printf("1");
			else 
				printf("0");//result ex)000001010
		}
		printf("\n계속 1, 종료 0 :");
		scanf_s("%d", &exit);
		printf("\n");
	}
	return 0;
}