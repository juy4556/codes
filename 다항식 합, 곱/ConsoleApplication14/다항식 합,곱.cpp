#include <iostream>
#include "Term.h"
#include "Polynomial.h"
using namespace std;

int main() {
	Polynomial A, B, C;
	int i, n, e;
	float c;
	cout << "다항식 A의 항의 수: ";
	cin >> n;
	for (i = 1; i <= n; i++) {
		cout << "다항식 A의 " << i << "번째 항의 계수와 지수: ";
		cin >> c >> e;
		A.NewTerm(c, e);
	}
	A.Print();
	cout << "다항식 B의 항의 수: ";
	cin >> n;
	for (i = 1; i <= n; i++) {
		cout << "다항식 B의 " << i << "번째 항의 계수와 지수: ";
		cin >> c >> e;
		B.NewTerm(c, e);
	}
	B.Print();
	C = A.Multiply(B);
	C.Print();

	return 0;
}