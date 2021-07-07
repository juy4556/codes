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
	printf("이름 : "); puts(staff.name);
	printf("주민등록번호 : ");puts(staff.IDCardNum);
	printf("급여: %d", staff.payroll);
	return 0;
}