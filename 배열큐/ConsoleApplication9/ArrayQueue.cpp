#include <iostream>

using namespace std;

/*template<class X> class Arrqueue{
private:
	X arrqueue;
}*/
class queue {
private:
	int front;
	int rear;
	int size;
	int* q;
public:
	queue(int n) { 
		front = 0;
		rear = -1;
		size = n; 
		q = new int[n]; }
	bool isfull() {
		if (rear>=size-1)return true;
		else return false;
	}
	bool isempty() {
		if (rear < front)return true;
		else return false;
	}
	int enque(int x);
	int deque();
	void peek();
	void print();
};
int queue::enque(int x) {
	if (isfull()) return -1;
	else {
		rear++;
		q[rear] = x;
		return 0;
	}
}
int queue::deque() {
	if (isempty()) return -1;
	else {
		front++;
		return 0;
	}
}
void queue::peek() {
	cout << q[front] << '\n';
}
void queue::print() {
	int a = front;
	int b = rear;
	while (a <= b) {
		printf("%d ", q[a++]);
	}
	putchar('\n');
}
int main() {
	int n;
	cin >> n;
	queue a(n);
	int num;
	int i=0;
	do {
		cout << "Queue에 넣을 값(그만 넣을 시 0입력): ";
		cin >> num;
		if(!num) break;
		a.enque(num);
		i++;
	} while (i<n);
	a.print();
	do {
		cout << "Dequeue: 1 그만:0 ";
		cin >> num;
		if (!num) break;
		a.deque();
		i++;
	} while (i<n);
	a.print();
	a.peek();

	return 0;
}