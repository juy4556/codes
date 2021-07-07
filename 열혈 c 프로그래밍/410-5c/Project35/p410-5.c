#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int i;
	int n;
	int cn1 = 0, cn2 = 0;
	srand((int)time(NULL));
	int r = rand() % 3 + 1;//r=3 n=1 & r=2 n=3 & r=1 n=2 
	for (i = 0;; i++) {
		printf("바위는 1, 가위는 2, 보는 3: ");
		scanf_s("%d", &n);
		if (n == 3 && r == 1) {
			printf("당신은 보 선택, 컴퓨터는 바위 선택, 이겼습니다!\n");
			cn1++;
		}
		else if (n == 2 && r == 3) {
			printf("당신은 가위 선택, 컴퓨터는 보 선택, 이겼습니다!\n");
			cn1++;
		}
		else if (n == 1 && r == 2) {
			printf("당신은 바위 선택, 컴퓨터는 가위 선택, 이겼습니다!\n");
			cn1++;
		}
		else if (n == 1 && r == 3) {
			printf("당신은 바위 선택, 컴퓨터는 보 선택, 당신이 졌습니다!\n");
			printf("\n\n 게임의 결과: %d승%d무",cn1,cn2);
			return 1;
		}
		else if (n == 3 && r == 2) {
			printf("당신은 보 선택, 컴퓨터는 가위 선택, 당신이 졌습니다!\n");
			printf("\n\n 게임의 결과: %d승%d무",cn1,cn2);
			return 1;
		}
		else if (n == 2 && r == 1) {
			printf("당신은 가위 선택, 컴퓨터는 바위 선택, 당신이 졌습니다!\n");
			printf("\n\n 게임의 결과: %d승%d무",cn1,cn2);
			return 1;
		}
		else if (n == 1 && r == 1) {
			printf("당신은 바위 선택, 컴퓨터는 바위 선택, 비겼습니다!\n");
			cn2++;
		}
		else if (n == 2 && r == 2) {
			printf("당신은 가위 선택, 컴퓨터는 가위 선택, 비겼습니다!\n");
			cn2++;
		}
		else if (n == 3 && r == 3) {
			printf("당신은 보 선택, 컴퓨터는 보 선택, 비겼습니다!\n");
			cn2++;
		}
	}
	return 0;
}