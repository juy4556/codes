#include <stdio.h>
#include <stdlib.h>

typedef struct bookinfo {
	char writer[10];
	char title[20];
	int page;
}Book;

int main(void) {
	int i;
	Book *book;
	book = malloc(sizeof(Book)*3);
	
	for (i = 0; i < 3; i++) {
		printf("���� ���� �Է�\n");
		printf("����: ");
		gets(book[i].writer);
		printf("����: ");
		gets(book[i].title);
		printf("������ ��: ");
		scanf_s("%d", &book[i].page);
		while (getchar() != '\n');
	}
	printf("���� ���� ���\n");
	for (i = 0; i < 3; i++) {
		printf("book %d\n", i + 1);
		printf("����: %s\n", book[i].writer);
		printf("����: %s\n", book[i].title);
		printf("������ ��: %d\n", book[i].page);
	}
	free(book);
	return 0;
}