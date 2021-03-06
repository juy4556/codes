#include <stdio.h>
int* pointer;
void f1(){
int i;
int* f1_ptr=&i;
printf("In func1\n");
*(f1_ptr+2) = *pointer;
}

void f2() {
	int j, * ptr;
	printf("f2 local: \t%p, \t%p\n", &j, &ptr);
	printf("In func2\n");
	*pointer = *(ptr + 3);
	*(ptr + 2) = (int)f1;
}

void f3() {
	printf("Before invoke f2()\n");
	f2();
	printf("After invoke f2()\n");
}

int main() {
	f3();
	return 0;
}