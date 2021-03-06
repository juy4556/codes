#include <iostream>
#include <sys/time.h>
using namespace std;

int main() {
	int i;
	struct timeval stime, etime, gap;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	gettimeofday(&stime, NULL);
	for (i = 0; i < 1000; i++)
		cout << "abc\n";
	gettimeofday(&etime, NULL);
	gap.tv_sec = etime.tv_sec - stime.tv_sec;
	gap.tv_usec = etime.tv_usec - stime.tv_usec;
	if (gap.tv_usec < 0) {
		gap.tv_sec = gap.tv_sec - 1;
		gap.tv_usec = gap.tv_usec + 1000000;
	}
	printf("%ldsec:%ldusec\n", gap.tv_sec, gap.tv_usec);
	return 0;
}