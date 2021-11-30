//팰린드롬 : 앞 뒤로 리버스해도 같은 문자열
#include <iostream>
using namespace std;
int dp[2001][2001];
int num[2001];
int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int N, M;
	cin >> N;// 수열의 크기
	for (int i = 1; i <= N; i++) {
		cin >> num[i];
		dp[i][i]=1;
		if (i != 1 && num[i - 1] == num[i]) {//num[1]부터 입력받기 때문에 i != 1
			dp[i - 1][i] = 1;//연속된 수가 같을 때 팰린드롬
		}
	}
	for (int i = 2; i <= N-1; i++) {
		for (int j = 1; i+j <= N ; j++) {
			{
				if (num[j] == num[i + j] && dp[j + 1][i + j - 1] == 1) {
					dp[j][i + j] = 1;
				}
			}
		}
	}

	cin >> M;//질문 개수
	int s, e;
	for (int i = 0; i < M; i++) {
		cin >> s >> e;
		cout << dp[s][e] << '\n';
	}

	return 0;
}