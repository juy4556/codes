/*
1. �迭 arr, �迭��ũ�� n, ���� k�� �Ű������� �޴� �Լ� func �ۼ�
	int func(int *arr, int n, int k)
�迭arr�� �� ���ҿ� ���� �ڱ� �ڽź��� ���� ���� ������ �� �ٸ� �迭cnt�� ����.
	��) arr = 10 40 30 60
		cnt = 0  2  1  3
k��°�� ū ���� ��ȯ��Ų��.
	��) k�� 2�̸� -> 30 ��ȯ*/
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