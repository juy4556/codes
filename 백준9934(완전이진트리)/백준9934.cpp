#include <iostream>
#include <cmath>

int main() {
	int k;//k는 1이상 10이하
	scanf_s("%d", &k);
	int n = (int)pow(2, k) - 1;//2^k-1
	int* tree = new int[n];
	for (int i = 0; i < n ;i++) {
		scanf_s("%d", &tree[i]);
	}
	int c = 0;
	for (int i = (n - 1) / 2;; i = i / 2) {
		int plus = (int)pow(2, k - c);
		for (int j = i; j < n; j += plus){		
			printf("%d ", tree[j]);
		}
		c++;
		putchar('\n');
		if (i == 0)break;
	}

	delete[]tree;
	return 0;
}