/*C3-Q9
bsearch함수와 같은 형식으로 호출할 수 있는 다음 함수를 작성.
이 때 Q5(p115)처럼 이진 검색 알고리즘을 사용하여 일치하는
요소의 검색에 성공하면 그 위치에서 앞쪽으로 선형 검색을 수행하여
가장 앞쪽의 요소에 대한 포인터를 반환하시오.
void *bsearchx(const void *key, const void *base,
size_t nmemb, size_t size,int(*compar)(const void *,const void *));
*/
#include <iostream>
#include <algorithm>

int compar(const int* a, const int* b);
void* bsearchx(const void* key, const void* base,
	size_t nmemb, size_t size, int(*compar)(const void*, const void*));
int main() {
	int n;
	scanf_s("%d", &n);
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &arr[i]);
	}
	std::sort(arr, arr + n);
	int key;
	scanf_s("%d", &key);
	int* p = (int*)bsearchx(&key, arr, n, sizeof(int),
		(int(*)(const void*, const void*))compar);
	if (p==NULL)
		printf("zzzz");
	else
		printf("key와 일치하는 배열원소값 중 가장 작은 배열 요소 값:%d", p - arr);
	delete[]arr;
	return 0;
}

int compar(const int* a, const int* b) {
	if (*a > * b)
		return 1;
	else if (*a < *b)
		return -1;
	else
		return 0;
}

void* bsearchx(const void* key, const void* base,
	size_t nmemb, size_t size, int(*compar)(const void*, const void*)) {
	char* b = (char*)base;
	size_t start = 0;
	size_t end = nmemb - 1;
	while (start <= end) {
		size_t mid = start + (end-start) / 2;
		if (!compar(b + (mid * size), key)) {
			while (!compar(b + ((--mid) * size), key));
			return (b + (++mid) * size);
		}
		else if (compar(b + (mid * size), key) > 0)
			end = mid - 1;
		else if (compar(b + (mid * size), key) < 0)
			start = mid + 1;
	}
	return NULL;
}