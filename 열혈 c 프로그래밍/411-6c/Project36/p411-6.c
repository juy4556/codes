#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int i;
	srand((int)time(NULL));
	int r1 = rand() % 10;
	int r2 = rand() % 10;
	int r3 = rand() % 10;
	int n1, n2, n3;
	int cn1, cn2;
	while (r2 == r1) {
		r2 = rand() % 10;
	}
	while (r3 == r1 || r3 == r2) {
		r3 = rand() % 10;
	}
	printf("Start Game!\n");
	for (i = 1;; i++) {
		cn1 = 0, cn2 = 0;
		printf("\n3개의 숫자 선택: ");
		scanf_s("%d", &n1);
		scanf_s("%d", &n2);
		scanf_s("%d", &n3);
		if (n1 == r1)
			cn1++;
		else if (n1 == r2 || n1 == r3)
			cn2++;
		if (n2 == r2)
			cn1++;
		else if(n2 == r1 || n2 == r3)
			cn2++;
		if (n3 == r3)
			cn1++;
		else if(n3 == r1 || n3 == r2)
			cn2++;
		if (cn1 == 3){
			printf("%d번째 도전 결과 : %dstrike, %dball!\n", i, cn1, cn2);
			printf("\n\nGame Over!");
			return 1;
		}
		printf("\n%d번째 도전 결과 : %dstrike, %dball!\n", i,cn1,cn2 );
	}

	return 0;
}