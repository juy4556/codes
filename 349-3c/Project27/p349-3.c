#include <stdio.h>
void Score(int a, int ary[5][5]) {
	int i;
	for (i = 0; i < 4; i++) {
			scanf_s("%d", &ary[a][i]);
	}
}
void PersonalTotal(int a, int ary[5][5]) {
	int total = 0;
	for (int i = 0; i < 4; i++) {
		total += ary[a][i];
	}
	ary[a][4] = total;
}
void SubjectTotal(int a, int ary[5][5]) {
	int total = 0;
	for (int j = 0; j < 4; j++) {
		total += ary[j][a];
	}
	ary[4][a] = total;
}

int main() {
	int arr[5][5];
	int i, j;
	int sum = 0;
	for (i = 0; i < 4; i++) {
		Score(i, arr);
	}
	for (i = 0; i < 4; i++) {
		PersonalTotal(i, arr);
		SubjectTotal(i, arr);
	}
	for (i = 0; i < 4; i++) {
		sum += arr[i][4];
	}
	arr[4][4] = sum;
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}