//baek1448(삼각형 만들기)
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	int* len = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> len[i];
	}
	sort(len, len + n);
	int a, b, c;
	for (int i = n-1; i > 1; i--) {
		a = len[i];
		b = len[i - 1];
		c = len[i - 2];
		if (a + b > c&& a + c > b&& b + c > a) {
			printf("%d", a + b + c);
			return 0;
		}
	}
	
	printf("-1");
	return 0;
}