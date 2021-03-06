/*
4. ��ǥ�� ����Ǿ��ִ� Ŭ���� �迭.
�� �� ������ �Ÿ� �� �ּڰ��� ��ȯ�ϴ� �Լ� MinDist() �ۼ�.
	class point {
	friend class dist; // ������Ŭ����
	private :
		int x, y
	}
	class dist{
		point *arr; // Ŭ���� �迭
	private :
		float MinDist();
	}
*/
#include <iostream>
#include <cmath>
using namespace std;

class point {
private:
	int x, y;
public:
	point() { x = 0; y = 0; }
	void get_xy(int a, int b) { x = a; y = b; }
	friend class dist;
};

class dist {
private:
	point* arr;
public:
	dist(int n) { arr = new point[n]; }
	void enter(point* p, int n);
	float MinDist(int n);
};
void dist::enter(point* p, int n) {
	for (int i = 0; i < n; i++)
		arr[i] = p[i];
}
float dist::MinDist(int n) {
	float min = sqrt(pow(arr[0].x - arr[1].x, 2) + pow(arr[0].y - arr[1].y, 2));
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (sqrt(pow(arr[i].x - arr[j].x, 2) + pow(arr[i].y - arr[j].y, 2)) < min)
				min = sqrt(pow(arr[i].x - arr[j].x, 2) + pow(arr[i].y - arr[j].y, 2));
		}
	}
	return min;
}
int main() {
	int size;
	int a = 0, b = 0;
	cout << "�迭ũ��: ";
	cin >> size;
	point* p = new point[size];
	dist d(size);
	for (int i = 0; i < size; i++) {
		cout << i + 1 << "��° ���� ��ǥ: ";
		cin >> a >> b;
		p[i].get_xy(a, b);
	}
	d.enter(p, size);
	cout << "�� �� ������ �Ÿ� �ּڰ�: " << d.MinDist(size);
	return 0;
}