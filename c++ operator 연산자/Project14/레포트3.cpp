#include <iostream>
using namespace std;

class coord {
private:
	int x, y;
public:
	coord() { x = 0; y = 0; }
	coord(int i, int j) { x = i; y = j; }
	void get_xy(int& i, int& j) { i = x; j = y; }
	bool operator==(coord op);
	bool operator&&(coord op);
};
bool coord::operator==(coord op) {
	if (x == op.x && y == op.y)
		return 1;
	else
		return 0;
}
bool coord::operator&&(coord op) {
	if ((x && op.x) && (y && op.y))
		return 1;
	else
		return 0;
}
int main() {
	coord a(1, 2), b(1, 2);
	if (a == b)
		cout << "a�� b�� ����" << endl;
	else
		cout << "a�� b�� �ٸ���" << endl;
	if (a && b) {
		cout << "a&&b �� ���̴�" << endl;
	}
	else
		cout << "a&&b�� �����̴�" << endl;

	return 0;
}