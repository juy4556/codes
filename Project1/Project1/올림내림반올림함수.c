#include <stdio.h>
#include <math.h>
void Comparison(double a[]) {
	int i;
	double max=a[0], min=a[0], mid=a[0];
	for (i = 0; i < 3; i++) {
			if (max < a[i])
				max = a[i];
			if (min > a[i])
				min = a[i];
	}
	for (i = 0; i < 3; i++) {
		if (a[i] != max && a[i] != min)
			mid = a[i];
	}
	printf("%d %d %d", (int)ceil(max), (int)floor(min), (int)round(mid));
}
int main() {
	int i;
	double a[3]={0};
	for (i = 0; i < 3; i++) {
		scanf("%lf", &a[i]);
	}
	Comparison(a);
	
	return 0;
}