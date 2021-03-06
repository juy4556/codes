//#2805 나무 자르기
#include <iostream>
#include <cstdio>
int n, m;
int high = 0;
int low = 0;
int mid;
long long sum=0;
int tree[1000001];
int ans;
void lsum(int height) {
	sum = 0;
	for (int a = 0; a < n; a++) {
		if (tree[a] > height)
			sum += (tree[a] - height);
	}
	return;
}
int main() {
	scanf("%d %d", &n, &m);//n:나무의 수 m:필요한 나무 길이  입력
	if (n < 1 || n>1000000)
		return -1;
	else if (m < 1 || m>2000000000)
		return -1;

	for (int i = 0; i < n; i++) {
		scanf("%d", &tree[i]);//나무의 길이 입력
		if (tree[i] < 0)
			return -1;
		if (high < tree[i])
			high = tree[i];
	}
	if (n == 1) {
		ans = high - m;
	}
	else {// n != 1
		while ((high - low) > 1) {
			mid = (high + low) / 2;//binary search
			lsum(mid);
			if (sum == m) {
				ans = mid;
				break;
			}
			else if (sum > m) {
				low = mid;
			}
			else if (sum < m) {
				high = mid;
			}
		}
		if (ans == 0) {/*high-low=1일 때
					   답은 high 일 때 또는 low 일 때 */
			lsum(high);
			if (sum>= m) { ans = high; }
			else {
				ans = low;
			}
		}
	}
	printf("%d", ans);

	return 0;
}