#include <stdio.h>
int main() {
	int a, z;
	for (a = 0; a <= 9; a++) {
		for (z = 0; z <= 9; z++) {
			if (10 * a + z + 10 * z + a==99) {
				printf("�̸� �����ϴ� a�� b�� ����: %d %d\n", a, z);
			}
		}
	}
	return 0;
}