#include <stdio.h>

typedef struct {
	double realnum;
	double imagnum;
}CN;
void ComplexPlus(CN c1,CN c2) {
	double real = c1.realnum + c2.realnum;
	double imaginary = c1.imagnum + c2.imagnum;
	printf("���� ���]�Ǽ�: %lf, ���: %lf\n", real,imaginary);
}

void ComplexMulti(CN c1,CN c2) {
	double real = (c1.realnum * c2.realnum) - (c1.imagnum * c2.imagnum);
	double imaginary = c1.realnum * c2.imagnum + c1.imagnum * c2.realnum;
	printf("���� ���]�Ǽ�: %lf, ���: %lf\n", real,imaginary);
}
int main() {
	CN cn[2];
	for (int i = 0; i <2 ; i++) {
		printf("���Ҽ� �Է�%d[�Ǽ� ���]: ",i+1);
		scanf_s("%lf %lf", &cn[i].realnum, &cn[i].imagnum);
	}
	ComplexPlus(cn[0], cn[1]);
	ComplexMulti(cn[0], cn[1]);
	return 0;
}