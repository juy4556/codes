//스택과 원형큐 구현
#include <iostream>
using namespace std;

template <class T>
class stack {
private:
	T* arr;
	int capacity;
	T top;
public:
	stack<T>(int c) {
	capacity = c;
	if (capacity < 1)throw "Capacity must be >0";
	arr = new T[capacity];
	top = -1;
	}
	void push(const T& x);
	T* pop(const T& x);
};
template <class T>
void stack<T>::push(const T&x) {
	if (top == capacity - 1) {
		capacity *= 2;
		arr = new T(capacity);
	}
	arr[++top] = x;
}
template <class T>
T* stack<T>::pop(const T& x) {
	if (top < 0)return 0;
	x = arr[top--];
	return &x;
}

template <class T>
class queue {
private:
	int front;
	int rear;
	int capacity;
	T* q;
public:
	queue(int c) {
		capacity = c;
		if (capacity < 1)throw "Capacity must be >0";
		q = new T(capacity);
		front = 0;
		rear = 0;
	}
	void push(const T& x);
	T* pop(T& x);
};
template <class T>
void queue<T>::push(const T& x) {
	if ((rear + 1) % capacity == front){//full
		capacity *= 2;
	q = new T[capacity];
	}
	rear = (rear + 1) % capacity;
	q[rear] = x;
}
template <class T>
T* queue<T>::pop(T& x) {
	if (front == rear)return 0;
	front = (front + 1) % capacity;
	x = q[front];
	return &x;
}
