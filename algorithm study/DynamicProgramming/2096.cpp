/*문제

N줄에 0 이상 9 이하의 숫자가 세 개씩 적혀 있다.내려가기 게임을 하고 있는데, 이 게임은 첫 줄에서 시작해서 마지막 줄에서 끝나게 되는 놀이이다.

먼저 처음에 적혀 있는 세 개의 숫자 중에서 하나를 골라서 시작하게 된다.그리고 다음 줄로 내려가는데, 다음 줄로 내려갈 때에는 다음과 같은 제약 조건이 있다.

바로 아래의 수로 넘어가거나, 아니면 바로 아래의 수와 붙어 있는 수로만 이동할 수 있다는 것이다.

숫자표가 주어져 있을 때, 얻을 수 있는 최대 점수, 최소 점수를 구하는 프로그램을 작성하시오.

점수는 원룡이가 위치한 곳의 수의 합이다.

####입력####

첫째 줄에 N(1 ≤ N ≤ 100, 000)이 주어진다.다음 N개의 줄에는 숫자가 세 개씩 주어진다.숫자는 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 중의 하나가 된다.

####출력####

첫째 줄에 얻을 수 있는 최대 점수와 최소 점수를 띄어서 출력한다.

출처:https://www.acmicpc.net/problem/2096  */
#include <iostream>
#include <algorithm>
using namespace std;
int arr[300003];
int main() {
	int N;//N은 1이상 100,000이하
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