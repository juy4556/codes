//5904 Moo ����
#include <iostream>
using namespace std;
int N;//1<=N<=10^9
int mid = 3;//�������
int s = 3;//��ü����
int main() {
    int len = 0;
    scanf_s("%d", &N);
    while (N > s) {
        mid++;
        s = s * 2 + mid;
    }
    while (1) {
        int len = (s - mid) / 2;

        if (N <= len) {//N�պκ��϶�
            mid--;
            s = len;
        }
        else if (N > len + mid) {//N�޺κ��϶�
            N -= len + mid;
            mid--;
            s = len;
        }
        else {//N�� ����κ��϶�
            N -= len;
            break;
        }
    }
    if (N == 1)cout << "m";//��� �κп��� ù��°(m) �����ϰ� ��� (o)
    else cout << "o";
    return 0;
}