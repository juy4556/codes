#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int i;
	int n;
	int cn1 = 0, cn2 = 0;
	srand((int)time(NULL));
	int r = rand() % 3 + 1;//r=3 n=1 & r=2 n=3 & r=1 n=2 
	for (i = 0;; i++) {
		printf("������ 1, ������ 2, ���� 3: ");
		scanf_s("%d", &n);
		if (n == 3 && r == 1) {
			printf("����� �� ����, ��ǻ�ʹ� ���� ����, �̰���ϴ�!\n");
			cn1++;
		}
		else if (n == 2 && r == 3) {
			printf("����� ���� ����, ��ǻ�ʹ� �� ����, �̰���ϴ�!\n");
			cn1++;
		}
		else if (n == 1 && r == 2) {
			printf("����� ���� ����, ��ǻ�ʹ� ���� ����, �̰���ϴ�!\n");
			cn1++;
		}
		else if (n == 1 && r == 3) {
			printf("����� ���� ����, ��ǻ�ʹ� �� ����, ����� �����ϴ�!\n");
			printf("\n\n ������ ���: %d��%d��",cn1,cn2);
			return 1;
		}
		else if (n == 3 && r == 2) {
			printf("����� �� ����, ��ǻ�ʹ� ���� ����, ����� �����ϴ�!\n");
			printf("\n\n ������ ���: %d��%d��",cn1,cn2);
			return 1;
		}
		else if (n == 2 && r == 1) {
			printf("����� ���� ����, ��ǻ�ʹ� ���� ����, ����� �����ϴ�!\n");
			printf("\n\n ������ ���: %d��%d��",cn1,cn2);
			return 1;
		}
		else if (n == 1 && r == 1) {
			printf("����� ���� ����, ��ǻ�ʹ� ���� ����, �����ϴ�!\n");
			cn2++;
		}
		else if (n == 2 && r == 2) {
			printf("����� ���� ����, ��ǻ�ʹ� ���� ����, �����ϴ�!\n");
			cn2++;
		}
		else if (n == 3 && r == 3) {
			printf("����� �� ����, ��ǻ�ʹ� �� ����, �����ϴ�!\n");
			cn2++;
		}
	}
	return 0;
}