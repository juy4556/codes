#include <iostream>
using namespace std;

int N[101];//���ΰ��Է�
int R[10100];//���

int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> N[i];
	}
	R[0] = 1;//�ƹ� ������ ���� X
	for (int i = 0; i < n; i++) {
		for (int j = N[i]; j <= k; j++) {
			R[j] = R[j] + R[j - N[i]];
		}
	}
	printf("%d", R[k]);
	return 0;
}