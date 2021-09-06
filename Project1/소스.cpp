/*
���� 2143 : �� �迭�� ��
�� �迭 A[1], A[2], ��, A[n]�� ���ؼ�, �� �迭�� A[i], A[i+1], ��, A[j-1], A[j] (��, 1 �� i �� j �� n)�� ���Ѵ�. �̷��� �� �迭�� ���� A[i]+��+A[j]�� �ǹ��Ѵ�. �� ���Ұ� ������ �� �迭 A[1], ��, A[n]�� B[1], ��, B[m]�� �־����� ��, A�� �� �迭�� �տ� B�� �� �迭�� ���� ���ؼ� T�� �Ǵ� ��� �� �迭 ���� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

���� ��� A = {1, 3, 1, 2}, B = {1, 3, 2}, T=5�� ���, �� �迭 ���� ������ ������ 7���� ��찡 �ִ�.

T(=5) = A[1] + B[1] + B[2]
      = A[1] + A[2] + B[1]
      = A[2] + B[3]
      = A[2] + A[3] + B[1]
      = A[3] + B[1] + B[2]
      = A[3] + A[4] + B[3]
      = A[4] + B[2]
�Է�
ù° �ٿ� T(-1,000,000,000 �� T �� 1,000,000,000)�� �־�����. ���� �ٿ��� n(1 �� n �� 1,000)�� �־�����, �� ���� �ٿ� n���� ������ A[1], ��, A[n]�� �־�����. ���� �ٿ��� m(1 �� m �� 1,000)�� �־�����, �� ���� �ٿ� m���� ������ B[1], ��, B[m]�� �־�����. ������ �迭 ���Ҵ� ������ 1,000,000�� ���� �ʴ� �����̴�.

���
ù° �ٿ� ���� ����Ѵ�. ������ ��찡 �� ������ ���� ��쿡�� 0�� ����Ѵ�.
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    long long t;
    int n, m;
    long long cnt = 0;
    int sum = 0;
    
    scanf("%lld", &t);
    scanf("%d", &n);
    int* a = new int[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &m);
    int* b = new int[m];
    for (int i = 0; i < m; i++) {
        scanf("%d", &b[i]);
    }
    vector <int> A, B;
    for (int i = 0; i < n; i++) {
        sum = 0;
        for (int j = i; j < n; j++) {
            sum += a[j];
            A.push_back(sum);
        }
    }
    for (int i = 0; i < m; i++) {
        sum = 0;
        for (int j = i; j < m; j++) {
            sum += b[j];
            B.push_back(sum);
        }
    }
    /* �޸� �ʰ�
    int tmp1 = (n * (n + 1)) / 2;
    int tmp2 = (m * (m + 1)) / 2;
    for (int i = 0; i < tmp1; i++) {
        for (int j = 0; j < tmp2; j++) {
            C.push_back(A[i] + B[j]);
        }
    }
    sort(C.begin(), C.end());
    cnt = upper_bound(C.begin(), C.end(), t)- lower_bound(C.begin(), C.end(), t);
    printf("%d\n", cnt);
    */
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    long long low1 = 0, high1 = A.size() - 1;
    long long low2 = 0, high2 = B.size() - 1;
    while (low1<=high1 && low2<=high2) {
        sum = A[low1] + B[high2];
        if (sum < t)low1++;
        else if (sum == t) {
            long long c1 = 1, c2 = 1;
            c1 = upper_bound(A.begin(), A.end(), A[low1]) - lower_bound(A.begin(), A.end(), A[low1]);
            c2 = upper_bound(B.begin(), B.end(), B[high2]) - lower_bound(B.begin(), B.end(), B[high2]);
            cnt += c1 * c2;
            low1 += c1;
            high2 -= c2;
            
        }
        else high2--;//sum>t�� ��
    }
    printf("%lld\n", cnt);
    delete[]a;
    delete[]b;
    return 0;
}