/*3. == ������ �ߺ� : �� �簢���� ������ ������ true �ٸ��� false ��ȯ.
class C {
private:
	int x1, x2;
	int y1, y2;
public:
	bool operator==(C op2);
	......
}
*/
#include <iostream>
#include <cmath>
using namespace std;

class C {
private:
	int x1, x2;
	int y1, y2;
public:
	C() { x1 = 0; x2 = 0; y1 = 0; y2 = 0; }
	C(int a, int b, int c, int d) { x1 = a; y1 = b; x2 = c; y2 = d; }
	bool operator==(C op2);
};
bool C::operator==(C op2) {
	if (abs(x2 - x1) * abs(y2 - y1) == abs(op2.x2 - op2.x1) * abs(op2.y2 - op2.y1))
		return true;
	else return false;
}

int main() {
	C a(1, 2, 3, 4), b(3, 4, 5, 6);
	if (a == b)
		cout << "���� ��" << '\n';
	else
		cout << "���� ��" << '\n';
	return 0;
}