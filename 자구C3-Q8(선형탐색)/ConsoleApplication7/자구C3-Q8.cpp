/*C3-Q8
bsearch함수와 같은 형식으로 호출할 수 있는 다음 함수를 이진 검색
알고리즘을 사용하여 작성.
void *binsearch(const void *key, const void *base, size_t nmemb,
size_t size, int(*compar)(const void *,const void *));
*/
#include<iostream>
#include<algorithm>
using namespace std;

int compar(const int* a, const int* b) {
	if (*a > * b)
		return 1;
	else if (*a < *b)
		return -1;
	else
		return 0;
}
void* binsearch(const void* key, const void* base, size_t nmemb,
	size_t size, int(*compar)(const void*, const void*));
int main() {
	int n;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &arr[i]);
	}
	sort(arr, arr + n);
	int key;
	cin >> key;
	int* p = (int*)binsearch(&key, arr, n, sizeof(int),
		(int(*)(const void*, const void*))compar);
	if (p==NULL)
		printf("아무 일도 없었다.");
	else
		printf("key와 일치하는 배열원소값의 요소값:%d", p - arr);
	delete[]arr;
	return 0;
}

void* binsearch(const void* key, const void* base, size_t nmemb,
	size_t size, int(*compar)(const void*, const void*)) {
	char* b = (char*)base;
	size_t start = 0;
	size_t end = nmemb - 1;
	while (start <= end) {
		size_t mid = start + (end - start) / 2;
		if (!compar((const void*)(&b[mid * size]), key))
			return (&b[mid * size]);
		else if (compar((const void*)(&b[mid * size]), key) > 0)
			end = mid - 1;
		else if (compar((const void*)(&b[mid * size]), key) < 0)
			start = mid + 1;
	}
	return NULL;
}