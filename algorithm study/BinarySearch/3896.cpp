//소수 사이 수열
/*연속한 소수 p와 p+n이 있을 때, 그 사이에 있는 n-1개의 합성수(소수나 1이 아닌 양의 정수)는 길이가 n인 소수 사이 수열라고 부른다.

양의 정수 k가 주어졌을 때, k를 포함하는 소수 사이 수열의 길이를 구하는 프로그램을 작성하시오. k를 포함하는 소수 사이 수열이 없을 때는 길이가 0이다.

예를 들어, 소수 23과 29의 소수 사이 수열은 {24, 25, 26, 27, 28}이고, 길이는 6이다.

입력
첫째 줄에 테스트 케이스의 개수 T가 주어진다. 테스트 케이스는 한 줄로 이루어져 있고, 한 줄에 정수 k가 주어진다. 각각의 정수는 1보다 크고, 100000번째 소수(1299709)와 작거나 같다.

출력
각각의 테스트 케이스에 대해서 k가 합성수라면 k를 포함하는 소수 사이 수열의 길이를 출력한다. 그렇지 않으면 0을 출력한다.
*/

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>
using namespace std;
//10 -> 7~11 사이 길이:4
//11 -> 소수 -> 길이:0
//27 -> 23~29 길이:6
//2 -> 소수 -> 길이:0

int number = 1299709;
int a[1299710];
vector<int> prime;

int binarySearch(int n) {
    int low = 2;//2와 3은 걸러지기 때문.
    int high = prime.size() - 1;
    int mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (prime[mid] >= n)high = mid - 1;
        else low = mid + 1;
    }
    return low;
}

int main() {
    int caseNum;
    int i = 0;
    scanf("%d", &caseNum);
    int* arr = new int[caseNum];
    //setPrimeNum(number + 1);//소수 미리 설정
    a[0] = 0;
    a[1] = 0;
    for (int i = 2; i <= number; i++) {
        a[i] = i;
    }
    for (int i = 2; i <= number; i++) {
        if (!a[i])continue;
        for (int j = i + i; j <= number; j += i) {
            a[j] = 0;//prime num 아니면 0 set
        }
    }
    for (int i = 2; i <= number; i++) {
        if (a[i]) prime.push_back(i);
    }
        for (i = 0; i < caseNum; i++) {
            scanf("%d", &arr[i]);
        }
        for (i = 0; i < caseNum; i++) {
            if (a[arr[i]])//0이 아니면(소수이면)
                printf("0\n");
            else {
                int index = binarySearch(arr[i]);
                printf("%d\n", prime[index] - prime[index-1]);
            }
        }

    delete[] arr;
    return 0;
}
