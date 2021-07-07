#include <stdio.h>

void main(void)
{
	char x = -128, y = -x;
	printf("%hhd, %hhd, %hhd, %hhd, %hhd\n", x, -x, y, -y, (-y) + y);
	printf("%hd, %hd, %hd, %hd, %hd\n", x, -x, y, -y, (-y) + y);
	printf("%d, %d, %d, %d, %d\n\n", x, -x, y, -y, (-y) + y);
	printf("0x%hhx, 0x%hhx, 0x%hhx, 0x%hhx, 0x%hhx\n", x, -x, y, -y, (-y) + y);
	printf("0x%hx, 0x%hx, 0x%hx, 0x%hx, 0x%hx\n", x, -x, y, -y, (-y) + y);
	printf("0x%x, 0x%x, 0x%x, 0x%x, 0x%x\n", x, -x, y, -y, (-y) + y);
}
