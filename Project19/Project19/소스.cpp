/*
2. class의 멤버함수 count_token()
	class C {
	private :
		char str[200];
		......
	public :
		int count_token();
		......
	}
str에 저장된 문자열의 토큰의 개수 출력하는 함수 작성.
*/
#include <iostream>
#include <cstdlib>
using namespace std;
class C {
private:
	char str[200];

public:
	void getstring(char* a) { strcpy_s(str, a); }
	int count_token();
};
int C::count_token() {
	char* p;
	p = str;
	int cnt=0;
	if(!p[0])return -1;
	while (*p) {
		if (*p == ' ')p++;
		else {
			while (*p != ' ' && *p) {
				p++;
			}
			cnt++;
		}
	}
	return cnt;
}

int main() {
	C c;
	char s[200];
	gets_s(s);
	c.getstring(s);
	cout << c.count_token();
	return 0;
}