#include <stdio.h>
#include <string.h>
//atoi(���ڿ� int��) atol(���ڿ�long����) atof(���ڿ�double��)
int main() {
	char nameage1[20];
	char nameage2[20];
	char str1[4];
	char str2[4];
	int i, j;
	int cn1 = 0, cn2 = 0;
	gets(nameage1);
	gets(nameage2);
	for (i = 0; nameage1[i] != ' '; i++) {
		cn1++;
	}
	for (j = 0; nameage2[j] != ' '; j++) {
		cn2++;
	}
	if (cn1 >= cn2) {
		if (!strncmp(nameage1, nameage2, cn2))
			printf("�� ����� �̸��� �����ϴ�\n");
		else
			printf("�� ����� �̸��� �ٸ��ϴ�\n");
	}
	else {
		if (!strncmp(nameage1, nameage2, cn1))
			printf("�� ����� �̸��� �����ϴ�\n");
		else
			printf("�� ����� �̸��� �ٸ��ϴ�\n");
	}
	for (i = 0; i < 3; i++) {
		str1[i] = nameage1[cn1 + (i + 1)];
		str2[i] = nameage2[cn2 + (i + 1)];
	}
	int age1 = atoi(str1);
	int age2 = atoi(str2);
	if (age1 == age2) {
		printf("�� ����� ���̴� �����ϴ�\n");
	}
	else
		printf("�� ����� ���̴� �ٸ��ϴ�\n");
	return 0;
}