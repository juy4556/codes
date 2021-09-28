#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;
int N;//2<=N<=11
int arithmetic[4];//사칙연산(덧,뺄,곱,나)각각의 수
int MAX = INT_MIN;
int MIN = INT_MAX;

void dfs(int a[], int sum, int index, int plus, int minus, int multi, int div) {
	
	if (index==N) {
		if (sum >= MAX) MAX = sum;//max
		if (sum <= MIN) MIN = sum;//min
		return;
	}
	if (plus < arithmetic[0])dfs(a, sum + a[index], index+1, plus+1, minus, multi, div);
	if (minus < arithmetic[1])dfs(a, sum - a[index], index+1, plus, minus+1, multi, div);
	if (multi < arithmetic[2])dfs(a, sum * a[index], index+1, plus, minus, multi+1, div);
	if (div < arithmetic[3])dfs(a, sum / a[index], index+1, plus, minus, multi, div+1);

}
int main() {
	scanf("%d", &N);
	int* A = new int[N+1];
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	for (int i = 0; i < 4; i++) {
		scanf("%d", &arithmetic[i]);
	}
	dfs(A,A[0],1,0,0,0,0);
	printf("%d\n%d\n", MAX, MIN);
	delete[]A;
	return 0;
}