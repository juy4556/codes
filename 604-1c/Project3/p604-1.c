#include <stdio.h>


 struct bookinfo {
	char writer[10];
	char title[20];
	int page;
}book[3];

int main(void) {
	int i;

	for (i = 0; i < 3; i++) {
		printf("도서 정보 입력\n");
		printf("저자: ");
		gets(book[i].writer);
		printf("제목: ");
		gets(book[i].title);
		printf("페이지 수: ");
		scanf_s("%d", &book[i].page);
		while (getchar() != '\n');
	}
	printf("도서 정보 출력\n");
	for (i = 0; i < 3; i++) {
		printf("book %d\n", i + 1);
		printf("저자: %s\n", book[i].writer);
		printf("제목: %s\n", book[i].title);
		printf("페이지 수: %d\n",book[i].page);
	}
	return 0;
}