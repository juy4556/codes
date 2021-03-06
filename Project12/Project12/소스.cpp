#include <iostream>
using namespace std;

class three_d {
private:
	int x, y, z;
public:
	three_d() { x = y = z = 0; }
	three_d(int i, int j, int k) { x = i; y = j; z = k;}
	three_d operator*(three_d op);
	three_d operator--();
	three_d operator--(int notused);
	void show();
};
three_d three_d::operator*(three_d op) {
	three_d temp;
	temp.x *= x * op.x;
	temp.y *= y * op.y;
	temp.z *= z * op.z;
	return temp;
}
three_d three_d::operator--() {
	x--;
	y--;
	z--;
	return *this;
}
three_d three_d::operator--(int notused) {
	three_d temp = *this;
	x--;
	y--;
	z--;
	return temp;
}
void three_d::show() {
	cout <<x<<y<<z<<endl;
}
int main() {
	three_d a(1, 2, 3), b(4, 5, 6), c;
	c = a * b;cout << "c=a*b : ";c.show();
	c = c * a; cout << "c=c*a : "; c.show();
	--c; cout << "--c : "; c.show();
	c--; cout << "c-- : "; c.show();
	a = c;
	a = --c; cout << "a=--c : ";a.show();
	a = c--; cout<< "a=c-- : "; a.show();

	return 0;
}