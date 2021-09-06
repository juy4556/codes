/*
문제 2143 : 두 배열의 합
한 배열 A[1], A[2], …, A[n]에 대해서, 부 배열은 A[i], A[i+1], …, A[j-1], A[j] (단, 1 ≤ i ≤ j ≤ n)을 말한다. 이러한 부 배열의 합은 A[i]+…+A[j]를 의미한다. 각 원소가 정수인 두 배열 A[1], …, A[n]과 B[1], …, B[m]이 주어졌을 때, A의 부 배열의 합에 B의 부 배열의 합을 더해서 T가 되는 모든 부 배열 쌍의 개수를 구하는 프로그램을 작성하시오.

예를 들어 A = {1, 3, 1, 2}, B = {1, 3, 2}, T=5인 경우, 부 배열 쌍의 개수는 다음의 7가지 경우가 있다.

T(=5) = A[1] + B[1] + B[2]
      = A[1] + A[2] + B[1]
      = A[2] + B[3]
      = A[2] + A[3] + B[1]
      = A[3] + B[1] + B[2]
      = A[3] + A[4] + B[3]
      = A[4] + B[2]
입력
첫째 줄에 T(-1,000,000,000 ≤ T ≤ 1,000,000,000)가 주어진다. 다음 줄에는 n(1 ≤ n ≤ 1,000)이 주어지고, 그 다음 줄에 n개의 정수로 A[1], …, A[n]이 주어진다. 다음 줄에는 m(1 ≤ m ≤ 1,000)이 주어지고, 그 다음 줄에 m개의 정수로 B[1], …, B[m]이 주어진다. 각각의 배열 원소는 절댓값이 1,000,000을 넘지 않는 정수이다.

출력
첫째 줄에 답을 출력한다. 가능한 경우가 한 가지도 없을 경우에는 0을 출력한다.
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
    /* 메모리 초과
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
        else high2--;//sum>t일 때
    }
    printf("%lld\n", cnt);
    delete[]a;
    delete[]b;
    return 0;
}