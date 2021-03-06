//bsearch함수(C언어 표준 라이브러리)
/*void *bsearch(const void *key, const void *base, 
				size_t nmemb, size_t size, 
				int(*compar)(const void*, const void*));
*/
#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
/*요소의 값이 내림차순으로 정렬된 long형 배열에서의 검색을
bsearch 함수를 사용하여 작성*/
int long_cmp(const long* a, const long* b) {//a:array element,b:key
	if (*a < *b)
		return 1;//내림차순이기 때문에 1반환
	else if (*a > * b)
		return -1;
	else 
		return 0;
}
bool desc(int a, int b) {
	return a > b;
}
int main() {
	long* p;
	long key;//찾을 수
	int n;//요소 개수
	printf("요소 개수 입력: ");
	scanf_s("%d", &n);
	long *arr = new long[n];
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &arr[i]);//배열입력
	}
	sort(arr, arr + n, desc);//bsearch 사용 위해 배열 정렬
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	printf("찾을 값:");
	scanf_s("%d", &key);
	p = (long*)bsearch(&key, arr, n, sizeof(long),
		(int(*)(const void*,const void*))long_cmp);
	if (p == NULL)
		printf("못 찾\n");
	else
		printf("%d는(은) arr[%d]", key, p-arr);
	delete[]arr;
	return 0;
}