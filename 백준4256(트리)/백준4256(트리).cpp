#include <iostream>
using namespace std;

int pre[1000];
int in[1000];

void postorder(int s, int e, int r) {
    for (int i = s; i < e; i++) {
        if (in[i] == pre[r]) {//중위순회에서 root찾고
            postorder(s, i, r + 1);//left먼저
            postorder(i + 1, e, r+ 1 + i-s);//right
            printf("%d ", pre[r]);
            return;
        }
    }
}

int main() {
    int t;//test case number
    int n;//node number(1~1000)

    scanf_s("%d", &t);//case num in
    for (int i = 0; i < t; i++) {
        scanf_s("%d", &n);//node num in
        for (int j = 0; j < n; j++) {
            scanf_s("%d", &pre[j]);//preorder input
        }
        for (int k = 0; k < n; k++) {
            scanf_s("%d", &in[k]);//inorder input
        }
        postorder(0, n, 0);
        putchar('\n');
    }

    return 0;
}