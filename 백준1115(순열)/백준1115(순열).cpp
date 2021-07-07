#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    int cycle = 0;
    scanf_s("%d", &n);//순열의 크기 입력
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {//순열 입력
        scanf_s("%d", &arr[i]);
    }
    vector<int> station;
    station.resize(n);
    int index = 0;
    while (1) {
        if (station[arr[index]] == 1) {//사이클 하나 다 돌면 실행
            cycle++;
            int count = 0;
            for (int i = 0; i < n; i++) {
                if (station[i] == 0) {
                    index = i;
                    break;
                }
                else count++;
            }
            if (count == n)break;//모든 요소 다 돌음
        }
        else {
            station[arr[index]] = 1;
            index = arr[index];
        }
    }
    if (cycle == 1)putchar('0');
    else    printf("%d", cycle);
    delete[]arr;
    return 0;
}