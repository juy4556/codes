#include <iostream>
#include <cmath>
using namespace std;

int main() {
	char str[31];
	cin >> str;
	int index = 0;
	int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
	int idx = 0;
	int result = 0;
	while (str[index] != NULL) {
		if (str[index] == '(')
			cnt1++;
		else if (str[index] == ')')
			cnt2++;
		else if (str[index] == '[')
			cnt3++;
		else if (str[index] == ']')
			cnt4++;
		index++;
	}

	if (cnt1 == cnt2 && cnt3 == cnt4) {//[( ]] 수 같을 때
		while (str[idx] != NULL) {
			cnt1 = cnt2 = cnt3 = cnt4 = 0;
			if ((str[idx] == '(' && str[idx + 1] == ']') ||
				(str[idx] == '[' && str[idx + 1] == ')')) {
				result = 0;
				break;
			}
			if ((str[idx] == '(' && str[idx + 1] == ')') ||
				str[idx] == '[' && str[idx + 1] == ']') {
				for (int i = 0; i < idx + 1; i++) {
					if (str[i] == '(')
						cnt1++;
					else if (str[i] == ')')
						cnt2++;
					else if (str[i] == '[')
						cnt3++;
					else if (str[i] == ']')
						cnt4++;
				}
				result += (int)pow(2, (cnt1 - cnt2)) * (int)pow(3, (cnt3 - cnt4));
			}
			idx++;
		}
		printf("%d", result);
	}
	else
		putchar('0');
	return 0;
}