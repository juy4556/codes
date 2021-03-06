#include <stdio.h>

int main() {
	FILE* src = NULL, * des = NULL;
	fopen_s(&src, "C:\\Users\\User\\Downloads\\C_Prog answer.zip", "rb");//읽어서 컴퓨터는 \하나를 문자로 인식하기 때문에 역슬래쉬 2개->\\
	fopen_s(&des, "C:\\Users\\User\\source\\repos\\Project3\\Project3\\Copy.zip", "wb");//복사
	char buf[20];
	int readCnt;

	if (src == NULL || des == NULL) {
		puts("파일오픈실패");
		return -1;
	}

	while (1) {
		readCnt = fread(buf, 1, sizeof(buf), src);

		if (readCnt < sizeof(buf)) {
			if(feof(src)!=0){
				fwrite(buf, 1, readCnt, des);
				puts("파일복사 완료");
				break;
			}
		else
			puts("파일복사 실패");

		break;
		}
		fwrite(buf, 1, sizeof(buf), des);
	}
	fclose(src);
	fclose(des);

	return 0;
}