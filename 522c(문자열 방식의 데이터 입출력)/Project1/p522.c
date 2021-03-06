#include <stdio.h>

int main() {
	FILE* fg = NULL;
	fopen_s(&fg, "mystory(문제1,2).txt", "rt");
	char str[30];
	if (fg == NULL) {
		puts("파일열기실패");
		return -1;
	}
	while (fgets(str, sizeof(str), fg) != NULL) {
		printf(str);
	}
	fclose(fg);
	return 0;
}