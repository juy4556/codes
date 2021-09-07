#include<iostream>
using namespace std;

int mylower_bound(int* arr, int n, int key) {
    int start = 0;
    int end = n;

    int mid = n;
    while (start<=end) {  //start 가 end 와 같지 않고, 넘지 않을 때
        mid = (start + end) / 2;    //중앙 index

        if (arr[mid] < key) { //key 값이 중앙 값보다 크면
            start = mid + 1;//mid 보다 오른쪽으로
        }
        else {  //key 값이 중앙값보다 작거나 같으면
            end = mid-1;  //mid 포함 왼쪽 (포함하는 이유는 key값과 같은게 없을 때 큰수중 가장 작은값을 위해)
        }

    }
    return start;
}

int myupper_bound(int* arr, int n, int key) {
    int start = 0;
    int end = n;

    int mid = n;
    while (start <= end) {  //start 가 end 와 같지 않고, 넘지 않을 때
        mid = (start + end) / 2;    //중앙 index

        if (arr[mid] <= key) { //key 값이 중앙 값보다 크거나 같으면
            start = mid + 1;//mid 보다 오른쪽으로
        }
        else {  //key 값이 중앙값보다 작으면
            end = mid - 1;//mid 포함 왼쪽 (포함하는 이유는 key값과 같은게 없을 때 큰수중 가장 작은값을 위해)
        }

    }
    return start;
}
int main(void) {
    int arr[11] = { 1, 2, 4, 5, 6, 6, 7, 7, 7, 9 };

    cout << "lower_bound(6) : " << mylower_bound(arr, 10, 6) << endl;
    cout << "lower_bound(7) : " << mylower_bound(arr, 10, 7) << endl;
    cout << "lower_bound(8) : " << mylower_bound(arr, 10, 8) << endl;
    cout << "lower_bound(9) : " << mylower_bound(arr, 10, 9) << endl;
    cout << "upper_bound(6) : " << myupper_bound(arr, 10, 6) << endl;
    cout << "upper_bound(7) : " << myupper_bound(arr, 10, 7) << endl;
    cout << "upper_bound(8) : " << myupper_bound(arr, 10, 8) << endl;
    cout << "upper_bound(9) : " << myupper_bound(arr, 10, 9) << endl;

    return 0;
}
