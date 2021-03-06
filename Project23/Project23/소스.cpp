#include <iostream>
#include <cstdio>
#include <ctime>
using namespace std;

int main() {
	int totalseconds = time(NULL);
	int currentsecond = totalseconds % 60;
	int totalminutes = totalseconds / 60;
	int currentminute = totalminutes % 60;
	int totalhours = totalminutes / 60 + 9;
	int currenthour = totalhours % 24;
	printf("%02d:%02d:%02d\n", currenthour,currentminute,currentsecond);
	int sh, sm, ss;
	cin >> sh>> sm>> ss;
	printf("%02d:%02d:%02d\n", sh, sm, ss);
	int currentseconds = currenthour * 3600 + currentminute * 60 + currentsecond;
	int startseconds = sh * 3600 + sm * 60 + ss;
	int dif=0;
	if (startseconds > currentseconds)
		dif = startseconds - currentseconds;

	else if (startseconds < currentseconds)
		dif = 24 * 3600 - (currentseconds - startseconds);

	int h, m, s;
	s = dif % 60;
	m = (dif / 60)%60;
	h = dif / 3600;

	printf("%02d:%02d:%02d\n", h, m, s);
	return 0;
}