#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	char str[31];
	cin >> str;
	int index = 0;
	int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
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
		if (cnt2 > cnt1 || cnt4 > cnt3)
			break;
		if (str[index - 1] == '(' && str[index] == ']')
			break;
		else if (str[index - 1] == '[' && str[index] == ')')
			break;
	}
	if (cnt1 == cnt2 && cnt3 == cnt4) {
		printf("1\n");
	}
	else printf("-1\n");
	return 0;
}