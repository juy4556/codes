#include <iostream>

int freelist[1000];
int s=0;
void* memoryalloc(size_t size) {
	int* ptr;
	*ptr = *(freelist + s);
	s += size;
	return ptr;
}
int main() {
	int* a = (int*)malloc(50);
	int* b = (int*)malloc(100);
	int* c = (int*)malloc(150);
	int* d = (int*)malloc(200);
	int* e = (int*)malloc(250);

	free(b);
	free(d);
	return 0;
}