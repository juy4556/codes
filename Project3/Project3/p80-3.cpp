#include <iostream>
using namespace std;

void SwapPointer(int* (&dptr1), int* (&dptr2)) {
	int* temp;
	temp = dptr1;
	dptr1 = dptr2;
	dptr2 = temp;
}
int main(){
	int num1 = 5;
	int* ptr1 = &num1;
	int num2 = 10;
	int* ptr2 = &num2;
	SwapPointer(ptr1, ptr2);
	cout << *ptr1 << ' ' << *ptr2 << endl;
	return 0;
}