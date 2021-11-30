//�Ӹ���� : �� �ڷ� �������ص� ���� ���ڿ�
#include <iostream>
using namespace std;
int dp[2001][2001];
int num[2001];
int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int N, M;
	cin >> N;// ������ ũ��
	for (int i = 1; i <= N; i++) {
		cin >> num[i];
		dp[i][i]=1;
		if (i != 1 && num[i - 1] == num[i]) {//num[1]���� �Է¹ޱ� ������ i != 1
			dp[i - 1][i] = 1;//���ӵ� ���� ���� �� �Ӹ����
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

	cin >> M;//���� ����
	int s, e;
	for (int i = 0; i < M; i++) {
		cin >> s >> e;
		cout << dp[s][e] << '\n';
	}

	return 0;
}