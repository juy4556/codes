#include <stdio.h>
int main() {
	int cur = 2;
	int is;
	do {
		is = 1;
		while(is<10){
			printf("%d * %d = %d\n", cur, is, (cur * is));
			is++;
		}
		cur++;
	} while (cur < 10);
	return 0;
}