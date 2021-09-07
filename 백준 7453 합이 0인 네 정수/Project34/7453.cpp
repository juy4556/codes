#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
/*
typedef struct {
	long long value, count;
}PAIR;*/
int main() {
	int n;//1<= n <=4000
	scanf_s("%d", &n);
	int* a = new int[n];//���� ������ �ִ� 2^28
	int* b = new int[n];
	int* c = new int[n];
	int* d = new int[n];
	int k = n * n;
	int* arr1 = new int[k];//�迭 a�� b ��
	int* arr2 = new int[k];//�迭 c�� d ��
	unsigned long long cnt = 0;
	for (int i = 0; i < n; i++) {
		scanf_s("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
	}
	int index1 = 0, index2 = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr1[index1++] = a[i] + b[j];
			arr2[index2++] = c[i] + d[j];
		}
	}
	delete[]a;
	delete[]b;
	delete[]c;
	delete[]d;

	sort(arr2, arr2 + k);//��������
	/*
	PAIR* arrFind = new PAIR[k + 1];
	arrFind[0].value = arr2[0];
	arrFind[0].count = 1;
	int x = 0;

	for (int i=1; i < k; i++) {
		if (arrFind[x].value == arr2[i]) {
			arrFind[x].count++;
		}
		else {
			x++;
			arrFind[x].value = arr2[i];
			arrFind[x].count = 1;
		}
	}
	*/
	//vector���
	vector<pair<long long, long long>> v;
	v.push_back(make_pair(arr2[0], 1));
	int x = 0;

	for (int i = 1; i < k; i++) {
		if (v[x].first == arr2[i])v[x].second++;
		else {
			x++;
			v.push_back(make_pair(arr2[i], 1));
		}
	}

	for (int i = 0; i < k; i++) {
		int key = (-1)* arr1[i];
		int left = 0, right = x;
		while (left <= right) {//����Ž��
			int mid = (left + right) / 2;
			if (v[mid].first < key)left = mid+1;
			else if (v[mid].first > key)right = mid-1;
			else { //arr2[mid] == key
				cnt += v[mid].second;
				break;
			}
		}
	}

	printf("%lld", cnt);
	delete[]arr1;
	delete[]arr2;
	
	return 0;
}