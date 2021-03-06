//#1477 휴게소 세우기(binary search)
#include <iostream>
#include <algorithm>

int main() {
	int rest[202];
	int n, m, l;//n:현재 휴게소 개수, m:더 지으려는 휴게소 개수, l:고속도로 길이
	scanf_s("%d %d %d", &n, &m, &l);
	if (n < 1 || n>100)//n<=100
		return -1;
	else if (m < 1 || m>100)//m<=100
		return -1;
	else if (l < 100 || l>1000)//100<=l<=1000
		return -1;
	else if (n + m >= l)
		return -1;
	rest[0] = 0;//시작점
	rest[n + 1] = l;//끝점
	for (int i = 1; i < n + 1; i++) {//휴게소 위치 입력
		scanf_s("%d", &rest[i]);
	}
	std::sort(rest, rest + n + 1);//작은 수부터 왼쪽정렬
	int max = 0;
	for (int j = 0; j < n + 1; j++) {//최대거리 구하고
		if (max < rest[j + 1] - rest[j]) {
			max = rest[j + 1] - rest[j];
		}
	}
	int start = 1, end = max;//1<=사이거리<=max
	int mid;
	int cnt;
	while (start <= end) {
		cnt = 0;//휴게소 카운트 초기화
		mid = (end + start) / 2;//binary search
		for (int k = 0; k < n + 1; k++) {
			if (mid <= rest[k + 1] - rest[k]) {
				cnt += ((rest[k + 1] - rest[k]) / mid);
			}
			if (((rest[k + 1] - rest[k]) % mid) == 0) {
				cnt--;
			}
		}//사이길이가 mid 이상이면 나눈 만큼 카운트
		if (cnt > m) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	printf("%d", start);
	return 0;
}