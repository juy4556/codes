//#1477 �ްԼ� �����(binary search)
#include <iostream>
#include <algorithm>

int main() {
	int rest[202];
	int n, m, l;//n:���� �ްԼ� ����, m:�� �������� �ްԼ� ����, l:��ӵ��� ����
	scanf_s("%d %d %d", &n, &m, &l);
	if (n < 1 || n>100)//n<=100
		return -1;
	else if (m < 1 || m>100)//m<=100
		return -1;
	else if (l < 100 || l>1000)//100<=l<=1000
		return -1;
	else if (n + m >= l)
		return -1;
	rest[0] = 0;//������
	rest[n + 1] = l;//����
	for (int i = 1; i < n + 1; i++) {//�ްԼ� ��ġ �Է�
		scanf_s("%d", &rest[i]);
	}
	std::sort(rest, rest + n + 1);//���� ������ ��������
	int max = 0;
	for (int j = 0; j < n + 1; j++) {//�ִ�Ÿ� ���ϰ�
		if (max < rest[j + 1] - rest[j]) {
			max = rest[j + 1] - rest[j];
		}
	}
	int start = 1, end = max;//1<=���̰Ÿ�<=max
	int mid;
	int cnt;
	while (start <= end) {
		cnt = 0;//�ްԼ� ī��Ʈ �ʱ�ȭ
		mid = (end + start) / 2;//binary search
		for (int k = 0; k < n + 1; k++) {
			if (mid <= rest[k + 1] - rest[k]) {
				cnt += ((rest[k + 1] - rest[k]) / mid);// mid�� ���� �� ��ŭ �ްԼ� �߰�
			}
			if (((rest[k + 1] - rest[k]) % mid) == 0) {// �� �ްԼ� ���̰Ÿ��� 2*mid�� ��� cnt�� 1�����ؾ� �ϱ� ������ cnt--
				cnt--;
			}
		}
		if (cnt > m) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	printf("%d", start);
	return 0;
}