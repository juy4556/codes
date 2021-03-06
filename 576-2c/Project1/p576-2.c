#include <stdio.h>
#define PI 3.14
#define SQUARE(X) ((X)*(X))
#define CIR_AREA(R) (SQUARE(R)*PI)

int main() {
	printf("¿øÀÇ ³ÐÀÌ: %lf", CIR_AREA(5));
	return 0;
}