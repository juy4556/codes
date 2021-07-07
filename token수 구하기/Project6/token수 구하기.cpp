#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	char str[30];
	char* p;
	int token = 0;
	while(1) {
		gets_s(str, 30);
		p = str;
		if (!*p)
			break;
		while (*p == ' ')p++;

		while (*p) {
			while (*p != ' ' && *p)
				p++;
			while(*p==' ')
				p++;
			token++;
		}
		
	}
	cout << "출력:총 토큰의 수: " << token;
	return 0;
}