#include <iostream>

int main() {
	long long int a, b;
	std::cin >> a >> b;//정수 입력
	long long int temp;
	long long int sum=0;
	if (a > b) {//계산의 편의를 위해 b를 항상 큰 수로
		temp = a;
		a = b;
		b = temp;
	}
	if (a == b) {//두 값 같을 때 두 정수 사이값
		sum = a;
	}
	else {// 두 값 다를 때
		if (a >= 0 && b > 0)//둘 다 양수
			sum = b * (b + 1) / 2 - (a - 1) * a / 2;
		else if (a < 0 && b <= 0) {// 둘 다 음수
			sum = ((a * (a - 1) / 2)* (-1)) + ((b * (b + 1) / 2) * (-1));
		}
		else if (a < 0 && b > 0)// 음 & 양
			sum = b * (b + 1) / 2 + (a * (a - 1) / 2) * -1;
	}
	std::cout << sum;
	return 0;
}