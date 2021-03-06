#include <iostream>
#include <cstdio>
using namespace std;

class LinkedStack;
class stack {
friend class LinkedStack;
private:
	int data;
	stack *link;
public:
	stack(int element = 0, stack* next = 0) {
		data = element; link = next;
	}
};
class LinkedStack {
private:
	stack* top;
public:
	LinkedStack() { top = 0; }
	void Push(const int& x);
	void Pop();
	void Print();
};
void LinkedStack::Push(const int& x) {
	top = new stack(x, top);
}
void LinkedStack::Pop() {
	if (top == 0)return;//빈스택
	stack* delNode = top;
	top = top->link;
	delete delNode;
}
void LinkedStack::Print() {
	stack* p;
	printf("스택(LIFO순):");
	for (p = top; p->link; p = p->link)
		printf("%d ", p->data);
	printf("%d\n", p->data);
}
class LinkedQueue;
class queue {
	friend class LinkedQueue;
private:
	int data;
	queue* link;
public:
	queue(int element = 0, queue* next = 0) {
		data = element; link = next;
	}
};
class LinkedQueue {
private:
	queue* front;
	queue* rear;
public:
	LinkedQueue() { front = 0; rear = 0; }
	void Push(const int& x);
	void Pop();
	void Print();
};
void LinkedQueue::Push(const int& x) {
	if (front == 0)front = rear = new queue(x, 0);//공백큐
	else rear = rear->link = new queue(x, 0);
}
void LinkedQueue::Pop() {
	if (front == 0)return;
	queue* delNode = front;
	front = front->link;
	delete delNode;
}
void LinkedQueue::Print() {
	queue* p;
	printf("큐(FIFO 순): ");
	for (p = front; p->link; p = p->link)
		printf("%d ", p->data);
	printf("%d", p->data);
}
int main() {
	LinkedStack a;
	LinkedQueue b;
	while (1) {
		int n,insert;
		scanf_s("%d", &n);
		switch (n) {
		case 1:
			scanf_s("%d", &insert);
			a.Push(insert);
			break;
		case 2:
			scanf_s("%d", &insert);
			b.Push(insert);
			break;
		case 3: a.Pop(); break;
		case 4: b.Pop(); break;
		case 5: a.Print(); break;
		case 6: b.Print(); break;
		case 0: return 0;
		}
	}
}