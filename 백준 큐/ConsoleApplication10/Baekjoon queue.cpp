#include <iostream>
#include <cstring>
int sloc = 0;
int rloc = -1;
int number = 0;

void empty(int* que) {
	if (number <= 0)printf("1\n");
	else printf("0\n");
}
void push(int* que, int num) {
	rloc++;
	que[rloc] = num;
	number++;
}
void pop(int* que) {
	if (number<=0)std::cout << "-1\n";
	else {
		std::cout << que[sloc] << '\n';
		sloc++;
		number--;
	}
}
void size(int* que) {
	printf("%d\n", number);
}
void front(int* que) {
	if (number<=0)std::cout <<"-1\n";
	else std::cout << que[sloc] << '\n';
}
void back(int* que) {
	if (number<=0)std::cout << "-1\n";
	else std::cout << que[rloc] << '\n';
}
int main() {
	int n;
	std::cin >> n;//명령의 수
	int num;
	int* q = new int[n];
	char str[6];
	for (int i = 0; i < n; i++) {
		std::cin >> str;
		if (!strcmp(str, "push")) {
			std::cin >> num;
			push(q, num);
		}
		else if (!strcmp(str, "pop")) {
			pop(q);
		}
		else if (!strcmp(str, "size")) {
			size(q);
		}
		else if (!strcmp(str, "empty")) {
			empty(q);
		}
		else if (!strcmp(str, "front")) {
			front(q);
		}
		else if (!strcmp(str, "back")) {
			back(q);
		}
	}

	delete[]q;
	return 0;
}