#include <stdio.h>

long GetFileSize(FILE* fg) {
	long fpos;
	long fsize;
	fpos = ftell(fg);

	fseek(fg, 0, SEEK_END);
	fsize = ftell(fg);
	fseek(fg, fpos, SEEK_SET);
	return fsize;
}
int main() {
	char str[100];
	FILE* fp = NULL;
	fopen_s(&fp, "p532.txt", "rt");
	fgets(str, 100, fp);
	fputs(str, stdout);
	printf("파일의 크기 : %ld \n", GetFileSize(fp));
	fgets(str, 100, fp);
	fputs(str, stdout);
	printf("파일의 크기: %ld \n", GetFileSize(fp));
	fgets(str, 100, fp);
	fputs(str, stdout);
	fclose(fp);
	return 0;
}