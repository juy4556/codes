#include <iostream>
using namespace std;
//���� �ٸ� N���� �ڿ����� ���� S, S�� �� ��, �ڿ��� N �ִ�?
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

