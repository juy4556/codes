/*
arr[i]=*(arr+i);
arr[3][2]=(*(arr+3))[2];
		 =*(arr[3]+2);
		 =*(*(arr+3)+2);
*/
#include <stdio.h>

int main() {
	int a[3][2] = { {1,2},{3,4},{5,6} };

	printf("a[0] : %p\n", a[0]);
	printf("*(a+0): %p\n", *(a + 0));

	printf("a[1] : %p\n", a[1]);
	printf("*(a+1): %p\n", *(a + 1));

	printf("a[2] : %p\n", a[2]);
	printf("*(a+2): %p\n", *(a + 2));

	printf("%d %d %d %d ", a[2][1], (*(a + 2))[1], *(a[2] + 1), *(*(a + 2) + 1));
	return 0;
}