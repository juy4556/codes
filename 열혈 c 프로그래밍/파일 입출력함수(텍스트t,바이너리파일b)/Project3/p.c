#include <stdio.h>

int main() {
	FILE* src = NULL, * des = NULL;
	fopen_s(&src, "C:\\Users\\User\\Downloads\\C_Prog answer.zip", "rb");//�о ��ǻ�ʹ� \�ϳ��� ���ڷ� �ν��ϱ� ������ �������� 2��->\\
	fopen_s(&des, "C:\\Users\\User\\source\\repos\\Project3\\Project3\\Copy.zip", "wb");//����
	char buf[20];
	int readCnt;

	if (src == NULL || des == NULL) {
		puts("���Ͽ��½���");
		return -1;
	}

	while (1) {
		readCnt = fread(buf, 1, sizeof(buf), src);

		if (readCnt < sizeof(buf)) {
			if(feof(src)!=0){
				fwrite(buf, 1, readCnt, des);
				puts("���Ϻ��� �Ϸ�");
				break;
			}
		else
			puts("���Ϻ��� ����");

		break;
		}
		fwrite(buf, 1, sizeof(buf), des);
	}
	fclose(src);
	fclose(des);

	return 0;
}