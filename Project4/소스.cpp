//5904 Moo 게임
#include <iostream>
using namespace std;
int N;//1<=N<=10^9
int mid = 3;//가운데길이
int s = 3;//전체길이
int main() {
    int len = 0;
    scanf_s("%d", &N);
    while (N > s) {
        mid++;
        s = s * 2 + mid;
    }
    while (1) {
        int len = (s - mid) / 2;

        if (N <= len) {//N앞부분일때
            mid--;
            s = len;
        }
        else if (N > len + mid) {//N뒷부분일때
            N -= len + mid;
            mid--;
            s = len;
        }
        else {//N이 가운데부분일때
            N -= len;
            break;
        }
    }
    if (N == 1)cout << "m";//가운데 부분에서 첫번째(m) 제외하고 모두 (o)
    else cout << "o";
    return 0;
}