#include <stdio.h>
#include <string.h>
//atoi(문자열 int로) atol(문자열long으로) atof(문자열double로)
int main() {
	char nameage1[20];
	char nameage2[20];
	char str1[4];
	char str2[4];
	int i, j;
	int cn1 = 0, cn2 = 0;
	gets(nameage1);
	gets(nameage2);
	for (i = 0; nameage1[i] != ' '; i++) {
		cn1++;
	}
	for (j = 0; nameage2[j] != ' '; j++) {
		cn2++;
	}
	if (cn1 >= cn2) {
		if (!strncmp(nameage1, nameage2, cn2))
			printf("두 사람의 이름은 같습니다\n");
		else
			printf("두 사람의 이름이 다릅니다\n");
	}
	else {
		if (!strncmp(nameage1, nameage2, cn1))
			printf("두 사람의 이름은 같습니다\n");
		else
			printf("두 사람의 이름이 다릅니다\n");
	}
	for (i = 0; i < 3; i++) {
		str1[i] = nameage1[cn1 + (i + 1)];
		str2[i] = nameage2[cn2 + (i + 1)];
	}
	int age1 = atoi(str1);
	int age2 = atoi(str2);
	if (age1 == age2) {
		printf("두 사람의 나이는 같습니다\n");
	}
	else
		printf("두 사람의 나이는 다릅니다\n");
	return 0;
}