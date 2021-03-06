/*Chapter3-Q7
bsearch 함수와 같은 형식으로 호출할 수 있는 다음 함수를 작성.
단, 선형 검색 알고리즘을 사용하고, 배열은 정렬되어 있지 않아도 됨.
void* seqsearch(const void* key, const void* base, size_t nmemb,
	size_t size, int(*compar)(const void*, const void*));
*/
#include <iostream>
#include <cstdlib>
using namespace std;
void* seqsearch(const void* key, const void* base, size_t nmemb,
	size_t size, int(*compar)(const void*, const void*));
int compar(const int* a, const int* b);

int main() {
	int n;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &arr[i]);
	}
	int key;
	cin >> key;
	int* p = (int*)seqsearch(&key, arr, n, sizeof(int),
		(int(*)(const void*, const void*))compar);
	if (p == NULL)
		printf("아무일도 없었다.\n");
	else
		printf("key와 일치하는 배열 원소의 배열 요소:%d", p-arr);
	delete[]arr;
	return 0;
}

int compar(const int* a, const int* b) {//b:key
	if (*a > * b)
		return 1;
	else if (*a < *b)
		return -1;
	else
		return 0;
}
void* seqsearch(const void* key, const void* base, size_t nmemb,
	size_t size, int(*compar)(const void*, const void*)) {
	char* x = (char*)base;
	for (size_t i = 0; i < nmemb; i++) {
		//&x[i*size]=x+(i*size)
		if (!compar((const void*)&x[i*size],key)) {
			return (&x[i * size]);
		}
	}
	return NULL;
}