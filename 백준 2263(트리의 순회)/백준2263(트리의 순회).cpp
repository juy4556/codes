#include <iostream>

int in[100000];
int post[100000];
int c;
void preorder(int s, int e, int r) {//start,end,root
	c = 0;
	for (int i = e-1; i >= s; i--) {
		c++;
		if (post[r]==in[i]) {//find root
			printf("%d ", post[r]);
			preorder(s, i, r - c);//left
			preorder(i+1, e, r - 1);//right
			return;
		}
	}
}
int main() {
	int n;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &in[i]);
	}
	for (int j = 0; j < n; j++) {
		scanf_s("%d", &post[j]);
	}
	preorder(0, n, n-1);
	return 0;
}