#include <iostream>

int main() {
	long long int a, b;
	std::cin >> a >> b;//���� �Է�
	long long int temp;
	long long int sum=0;
	if (a > b) {//����� ���Ǹ� ���� b�� �׻� ū ����
		temp = a;
		a = b;
		b = temp;
	}
	if (a == b) {//�� �� ���� �� �� ���� ���̰�
		sum = a;
	}
	else {// �� �� �ٸ� ��
		if (a >= 0 && b > 0)//�� �� ���
			sum = b * (b + 1) / 2 - (a - 1) * a / 2;
		else if (a < 0 && b <= 0) {// �� �� ����
			sum = (a * (a - 1) / 2 + (b * (b + 1) / 2) * -1) * -1;
		}
		else if (a < 0 && b > 0)// �� & ��
			sum = b * (b + 1) / 2 + (a * (a - 1) / 2) * -1;
	}
	std::cout << sum;
	return 0;
}