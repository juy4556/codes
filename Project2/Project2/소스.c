#include <stdio.h>
int main()
{
	int N, cnt = 0;
	printf("������ �Է��Ͻÿ� : ");
	scanf_s("%d", &N);
	printf("%d�� ���: ", N);
	for (int i = 1; i <= N; i++)
	{
		if (N % i == 0) {
			printf("%d ", i);
			cnt++;
		}
	}
	printf("\n����� ����: %d", cnt);
	return 0;
}