#include <stdio.h>
#include <string.h>
ClearLineFromReadBuffer() {
	while (getchar() != '\n');
}
struct employee {
	char name[20];
	char IDCardNum[20];
	int payroll;
};
int main() {
	struct employee staff[3] = {0};
	for (int i = 0; i < 3; i++) {
		printf("%d��° EMPLOYEE ���� �Է�\n",i+1);
		printf("�̸� �Է�: "); gets(staff[i].name);
		printf("�ֹε�Ϲ�ȣ �Է�: "); gets(staff[i].IDCardNum);
		printf("�޿� �Է�: "); scanf_s("%d", &staff[i].payroll);
		ClearLineFromReadBuffer();
		}
	for (int j = 0; j < 3; j++) {
		printf("%d��° EMPLOYEE �̸� : ",j+1); puts(staff[j].name);
		printf("�ֹε�Ϲ�ȣ : "); puts(staff[j].IDCardNum);
		printf("�޿�: %d\n", staff[j].payroll);
	}
	return 0;
}