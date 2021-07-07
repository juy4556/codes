/*3. == 연산자 중복 : 두 사각형의 면적이 같으면 true 다르면 false 반환.
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
		cout << "면적 같음" << '\n';
	else
		cout << "면적 다름" << '\n';
	return 0;
}