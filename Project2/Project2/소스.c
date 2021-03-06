#include <stdio.h>
int main()
{
	int N, cnt = 0;
	printf("정수를 입력하시오 : ");
	scanf_s("%d", &N);
	printf("%d의 약수: ", N);
	for (int i = 1; i <= N; i++)
	{
		if (N % i == 0) {
			printf("%d ", i);
			cnt++;
		}
	}
	printf("\n약수의 개수: %d", cnt);
	return 0;
}