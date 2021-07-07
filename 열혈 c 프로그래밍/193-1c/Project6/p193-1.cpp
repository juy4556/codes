#include <stdio.h>
int main() {
	int cur, is;
	for (cur = 2; cur <= 9; cur++) {
		for (is = 1; is <= 9; is++) {
			if (cur >= is && cur % 2 == 0)
				printf("%d*%d=%d\n", cur, is, cur * is);
			else
				continue;
		}
	}
	return 0;
}