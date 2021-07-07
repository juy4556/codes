#include <stdio.h>
#include <string.h>

int main() {
	char str1[20];
	char str2[20];
	char str3[40];
	int cn1=0, cn2=0;
	fgets(str1, sizeof(str1), stdin);
	fgets(str2, sizeof(str2), stdin);
	for (int i = 0; str1[i] != '\n'; i++) {
		cn1++;
	}
	for (int j = 0; str2[j] != '\n'; j++) {
		cn2++;
	}
	strncpy_s(str3,40, str1, cn1);
	strncat_s(str3,40, str2, cn2);
	puts(str3);

	return 0;
}