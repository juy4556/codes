#include <iostream>
using namespace std;

int main() {
	int p, q, w;
	cin >> p >> q >> w;
	int a = 0;
	int b = 0;
	while (1) {
		a++;
		if ((w - a * p) % q == 0) {
			b = (w - a * p) / q;
			break;
		}
	}
	cout << a << ' ' << b;
	return 0;
}