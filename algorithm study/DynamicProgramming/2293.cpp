#include <iostream>
using namespace std;
int C[101];//Coin value 종류
int dp[10100];
int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> C[i];
	}
	dp[0] = 1;//아무 동전도 선택 안한 것도 하나의 경우의 수
	for (int i = 0; i < n; i++) {
		for (int j = C[i]; j <= k; j++) {
			dp[j] += dp[j - C[i]];
		}
	}
	printf("%d\n", dp[k]);

	return 0;
}