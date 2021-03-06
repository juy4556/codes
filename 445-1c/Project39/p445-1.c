#include <stdio.h>
#include <string.h>

int main() {
	char str[20];
	int sum = 0;
	fgets(str,sizeof(str),stdin);
	for (int i = 0; i < sizeof(str)-1; i++) {
		if (str[i] >= 48 && str[i] <= 57) {
			sum += str[i];
			sum -= 48;
		}
	}
	printf("гу: %d", sum);
	return 0;
}