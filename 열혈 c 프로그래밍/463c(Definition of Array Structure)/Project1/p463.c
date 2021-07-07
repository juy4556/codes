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
		printf("%d번째 EMPLOYEE 정보 입력\n",i+1);
		printf("이름 입력: "); gets(staff[i].name);
		printf("주민등록번호 입력: "); gets(staff[i].IDCardNum);
		printf("급여 입력: "); scanf_s("%d", &staff[i].payroll);
		ClearLineFromReadBuffer();
		}
	for (int j = 0; j < 3; j++) {
		printf("%d번째 EMPLOYEE 이름 : ",j+1); puts(staff[j].name);
		printf("주민등록번호 : "); puts(staff[j].IDCardNum);
		printf("급여: %d\n", staff[j].payroll);
	}
	return 0;
}