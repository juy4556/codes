#include<iostream>
using namespace std;

int mylower_bound(int* arr, int n, int key) {
    int start = 0;
    int end = n;

    int mid = n;
    while (start<=end) {  //start �� end �� ���� �ʰ�, ���� ���� ��
        mid = (start + end) / 2;    //�߾� index

        if (arr[mid] < key) { //key ���� �߾� ������ ũ��
            start = mid + 1;//mid ���� ����������
        }
        else {  //key ���� �߾Ӱ����� �۰ų� ������
            end = mid-1;  //mid ���� ���� (�����ϴ� ������ key���� ������ ���� �� ū���� ���� �������� ����)
        }

    }
    return start;
}

int myupper_bound(int* arr, int n, int key) {
    int start = 0;
    int end = n;

    int mid = n;
    while (start <= end) {  //start �� end �� ���� �ʰ�, ���� ���� ��
        mid = (start + end) / 2;    //�߾� index

        if (arr[mid] <= key) { //key ���� �߾� ������ ũ�ų� ������
            start = mid + 1;//mid ���� ����������
        }
        else {  //key ���� �߾Ӱ����� ������
            end = mid - 1;//mid ���� ���� (�����ϴ� ������ key���� ������ ���� �� ū���� ���� �������� ����)
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
