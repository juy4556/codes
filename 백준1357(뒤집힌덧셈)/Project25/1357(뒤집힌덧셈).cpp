#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int x, y;
	cin >> x >> y;
	if (x > 1000 || y > 1000)
		return -1;
	else if (x < 0 || y < 0)
		return -1;
	int a[4], b[4];
	a[0] = x / 1000;
	a[1] = (x-1000*a[0]) / 100;
	a[2] = (x-1000*a[0]-100*a[1]) / 10;
	a[3] = x % 10;
	
	b[0] = y / 1000;
	b[1] = (y - 1000 * b[0]) / 100;
	b[2] = (y - 1000 * b[0] - 100 * b[1]) / 10;
	b[3] = y % 10;
	int revx=0;
	int revy=0;
	for (int i = 0; i < 4; i++) {
		if (a[i] != 0) {
			int index = 3;
			for (int j = i; j <=3; j++) {
					revx += a[index] * pow(10, 3 - j);
					index--;
			}
			break;
		}
	}
	for (int k = 0; k < 4; k++) {
		if (b[k] != 0) {
			int index = 3;
			for (int l = k; l <= 3; l++) {
				revy += b[index] * pow(10, 3 - l);
				index--;
			}
			break;
		}
	}
	int sum = revx + revy;
	int c[4];
	c[0] = sum / 1000;
	c[1] = (sum - 1000 * c[0]) / 100;
	c[2] = (sum - 1000 * c[0] - 100 * c[1]) / 10;
	c[3] = sum % 10;
	int rev=0;
	for (int m = 0; m < 4; m++) {
		if (c[m] != 0) {
			int index = 3;
			for (int n = m; n <= 3; n++) {
				rev += c[index] * pow(10, 3 - n);
				index--;
			}
			break;
		}
	}
	cout << rev;
	return 0;
}