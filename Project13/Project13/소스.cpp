#include <iostream>
using namespace std;
//서로 다른 N개의 자연수의 합이 S, S를 알 때, 자연수 N 최댓값?
int main() {
	long long num;
	int i;
	int cnt = 0;
	long long s1 = 0;
	cin >> num;
	for (i = 1;; i++) {
		s1 += i;
		if (s1 > num) {
			cnt = i - 1;
			break;
		}
		else if (s1 == num) {
			cnt = i;
			break;
		}
		else
			continue;
	}
	cout << cnt;
	return 0;
}

