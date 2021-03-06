#include <iostream>
class Stack {
private:
	int top;
	int* stack;
	int num = 6;
public:
	Stack() { top = -1; stack = new int[num]; }
	void Push(int n);
	void Pop();
	bool Empty();
};
void Stack::Push(int n) {
	if (top == num) {
		int* temp = new int[num * 2];
		for (int i = 0; i < n; i++) {
			temp[i] = stack[i];
		}
		stack = temp;
		delete[]temp;
	}
	stack[++top] = n;
}
void Stack::Pop() {
	if (!Empty())
		printf("%d ", stack[top--]);
}
bool Stack::Empty() {
	if (top < 0)return true;
	else return false;
}
int main() {
	Stack stack;
	stack.Push(1);
	stack.Push(1);
	stack.Push(1);
	stack.Push(1);
	stack.Push(1);
	while (!stack.Empty())stack.Pop();
	int ep = 1;
	int sp = 0;
	int path[6] = { 0,4,0,0,3,0 };
	stack.Push(ep);//종점 push
	int temp = path[ep];
	while (temp != sp) {
		stack.Push(temp);
		temp = path[temp];
		printf("너냐?");
	}
	stack.Push(sp);//시작점 push
	printf("하");
	while (!stack.Empty())stack.Pop();
	printf("어디야");
	putchar('\n');
}