#include <stdio.h>

struct employee {
	char name[10];
	char IDCardNum[20];
	int payroll;
};
int main() {
	struct employee staff;
	gets(staff.name);
	gets(staff.IDCardNum);
	scanf_s("%d", &staff.payroll);
	printf("�̸� : "); puts(staff.name);
	printf("�ֹε�Ϲ�ȣ : ");puts(staff.IDCardNum);
	printf("�޿�: %d", staff.payroll);
	return 0;
}