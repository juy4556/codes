/*
1. 배열 arr, 배열의크기 n, 정수 k를 매개변수로 받는 함수 func 작성
	int func(int *arr, int n, int k)
배열arr의 각 원소에 대해 자기 자신보다 작은 수의 개수를 또 다른 배열cnt에 저장.
	예) arr = 10 40 30 60
		cnt = 0  2  1  3
k번째로 큰 수를 반환시킨다.
	예) k가 2이면 -> 30 반환*/
#include <iostream>
using namespace std;

int func(int* arr, int n, int k) {
	int* cnt;
	cnt = new int[n];
	int count;
	int a = 0;
	for (int i = 0; i < n; i++) {
		count = 0;
		for (int j = 0; j < n; j++) {
			if (arr[i] > arr[j]) {
				count++;
			}
		}
		cnt[i] = count;
		if (count == n-k)
			a = arr[i];
	}
	delete[]cnt;
	return a;
}

int main() {
	int num,q;
	cout << "�迭�� ũ�� �Է�: ";
	cin >> num;
	int* arr = new int[num];
	cout << "���° ū ��?: ";
	cin >> q;
	cout << "�迭 �Է�: ";
	for (int i = 0; i < num; i++) {
		cin >> arr[i];
	}
	cout<<"q��°�� ū ��: "<<func(arr, num, q)<<'\n';
	delete[]arr;
	return 0;
}