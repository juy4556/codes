/*����

N�ٿ� 0 �̻� 9 ������ ���ڰ� �� ���� ���� �ִ�.�������� ������ �ϰ� �ִµ�, �� ������ ù �ٿ��� �����ؼ� ������ �ٿ��� ������ �Ǵ� �����̴�.

���� ó���� ���� �ִ� �� ���� ���� �߿��� �ϳ��� ��� �����ϰ� �ȴ�.�׸��� ���� �ٷ� �������µ�, ���� �ٷ� ������ ������ ������ ���� ���� ������ �ִ�.

�ٷ� �Ʒ��� ���� �Ѿ�ų�, �ƴϸ� �ٷ� �Ʒ��� ���� �پ� �ִ� ���θ� �̵��� �� �ִٴ� ���̴�.

����ǥ�� �־��� ���� ��, ���� �� �ִ� �ִ� ����, �ּ� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

������ �����̰� ��ġ�� ���� ���� ���̴�.

####�Է�####

ù° �ٿ� N(1 �� N �� 100, 000)�� �־�����.���� N���� �ٿ��� ���ڰ� �� ���� �־�����.���ڴ� 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 ���� �ϳ��� �ȴ�.

####���####

ù° �ٿ� ���� �� �ִ� �ִ� ������ �ּ� ������ �� ����Ѵ�.

��ó:https://www.acmicpc.net/problem/2096  */
#include <iostream>
#include <algorithm>
using namespace std;
int arr[300003];
int main() {
	int N;//N�� 1�̻� 100,000����
	cin >> N;
	int sumMin[3] = { 0 };
	int sumMax[3] = { 0 };
	
	cin >> arr[0] >> arr[1] >> arr[2];
	for (int i = 0; i < 3; i++) {
		sumMin[i] += arr[i];
		sumMax[i] += arr[i];
	}
	for (int i = 1; i < N; i++) {
		int index = 3 * i;
		cin >> arr[index] >> arr[index + 1] >> arr[index + 2];
		
		sumMin[0] += std::min(arr[index], arr[index + 1]);
		sumMin[1] += std::min({ arr[index],arr[index + 1],arr[index + 2] });
		sumMin[2] += std::min(arr[index+1], arr[index + 2]);
		sumMax[0] += std::max(arr[index], arr[index + 1]);
		sumMax[1] += std::max({ arr[index],arr[index + 1],arr[index + 2] });
		sumMax[2] += std::max(arr[index + 1], arr[index + 2]);
	}
	int min, max;
	min = std::min({ sumMin[0],sumMin[1],sumMin[2] });
	max = std::max({ sumMax[0],sumMax[1],sumMax[2] });

	cout << max << ' ' << min;
	return 0;
}