#include <iostream>
using namespace std;

template<class X>int find(X object, X* list, int size) {
	int f=0;
	for (int i = 0; i <= size; i++) {
		if (list[i] == object) {
			f = i;
			break;
		}
		if (i == size)
			f = -1;
	}
	return f;
}
int main() {
	int a = 5;
	int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
	cout << "intÇü: "<<find(a,arr1,10)<<'\n';
	float b = 7.7;
	float arr2[10] = { 1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9,10.10 };
	cout << "floatÇü: "<<find(b, arr2, 10)<<'\n';
	char c = 'c';
	char arr3[30] = "abcdefghijklmlopqrstuvwxyz";
	int s;
	for (int i = 0;; i++) {
		if (arr3[i] == NULL) {
			s = i;
			break;
		}
	}
	cout << "charÇü: " << find(c, arr3, s) << '\n';
	return 0;
}