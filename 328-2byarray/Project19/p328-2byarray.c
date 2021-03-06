#include <stdio.h>

int main() {
	int arr[8] = { 0 };
	int num,temp=1;
	int count=0;
	printf("Decimal To BinaryÇØºÁ¶ó ÀÚ½»¾Æ\n");
	scanf_s("%d", &num);//ex num =10
	for (int i = 0; num>=temp ; i++) {//temp°¡ 10(num) ³ÑÀ» ¶§ -> temp = 16, count =4 
		temp *= 2;
		count++;
	}
	for (int j = count-1; j >= 0; j--) {
		if (num % 2 == 1)
			arr[j] = 1;
		else
			arr[j] = 0;
		num /= 2;
	}
	for (int k = 0; k <= count-1; k++) {
		printf("%d", arr[k]);
	}
	return 0;
}