#include <iostream>
#include <cmath>
using namespace std;

void PsquareNum(int a, int b) {
	int sum = 0;
	int c;
	int min=0;
	for (c = b; c >= a; c--) {
		for (int i = (int)sqrt(a); i <= (int)sqrt(b); i++) {
			if (c == i * i){
				sum += c;
				min = c;
			}
		}
	}
	if (sum != 0)
		cout << sum << endl << min;
	else
		cout << "-1";
}
int main() {
	int n;
	int m;
	while (1) {
		cin >> m >> n;
		if(n<=10000&&m<=n)
			break;
	}
	PsquareNum(m, n);
	return 0;
}