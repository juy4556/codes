#include <iostream>
using namespace std;

int N[101];//코인값입력
int R[10100];//결과

int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> N[i];
	}
	R[0] = 1;//아무 동전도 선택 X
	for (int i = 0; i < n; i++) {
		for (int j = N[i]; j <= k; j++) {
			R[j] = R[j] + R[j - N[i]];
		}
	}
	printf("%d", R[k]);
	return 0;
}