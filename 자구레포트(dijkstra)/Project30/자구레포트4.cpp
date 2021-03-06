#include <iostream>
#define INF 9999
class Graph;
class Stack {
	friend class Graph;
private:
	int top;
	int* stack;
	int num=6;
public:
	Stack() { top = -1; stack = new int[num]; }
	void Push(int n);
	void Pop();
	bool Empty();
};
void Stack::Push(int n) {
	if (top == num) {
		int *temp = new int[num*2];
		for (int i = 0; i < n; i++) {
			temp[i] = stack[i];
		}
		stack = temp;
		delete[]temp;
	}
	stack[++top] = n;
}
void Stack::Pop() {
	if(!Empty())
	printf("%d ",stack[top--]);
}
bool Stack::Empty() {
	if (top < 0)return true;
	else return false;
}

class Graph {
private:
	int **length;
	int *dist;
	bool *s;
	int n;//������ ��
	int *path;
	Stack stack;
public:
	Graph(const int vertices = 0) :n(vertices) {
		length = new int*[n];
		for (int i = 0; i < n; i++) { 
			length[i] = new int[n];
			for (int j = 0; j < n; j++) {
				if (i == j)length[i][j] = 0;
				else
				length[i][j] = INF;
			}
		}
		dist = new int[n];
		s = new bool[n];
		path = new int[n];
	}
	void ShortestPath(const int);
	int choose(const int);
	void InsertLength(int a, int b, int c);
	void Matrix();
	void DistValue();
	void PrintShortestPath(int,int);
};
void Graph::ShortestPath(const int v) {
	for (int i = 0; i < n; i++) { 
		s[i] = false; 
		dist[i] = length[v][i];
		path[i] = v;
	}
	s[v] = true;//��� ���� s���տ� �����ϰ� ����
	dist[v] = 0;
	for (int i = 0; i < n - 2; i++) {//n-2�� ����(�ʱ� ���� ������ �̸� ���ԵǱ� ����)
		int u = choose(n);
		s[u] = true;
		for (int w = 0; w < n; w++) {
			if (!s[w])
				if (dist[u] + length[u][w] < dist[w]) {
					dist[w] = dist[u] + length[u][w];
					path[w] = u;
				}
		}
	}
}
int Graph::choose(const int n) {
	int min = 9999;
	int ret=0;
	for (int w = 0; w < n; w++) {
		if (!s[w])
			if (min > dist[w]&&dist[w]>0) {
				min = dist[w];
				ret = w;
			}
	}
	return ret;
}
void Graph::InsertLength(int a, int b, int c) {
	length[a][b] = c;
}
void Graph::Matrix() {
	printf("   ");
	for (int i = 0; i < n; i++)printf("%6d", i); putchar('\n');
	for (int i = 0; i < n; i++) {
		printf("%d  ", i);
		for (int j = 0; j < n; j++) {
			printf("%6d", length[i][j]);
		}
		putchar('\n');
	}
}
void Graph::DistValue() {
	for (int i = 0; i < n; i++) {
		printf("%5d", dist[i]);
	}
	putchar('\n');
}
void Graph::PrintShortestPath(int sp,int ep) {//start point, end point
	if (dist[ep]>0&&dist[ep]<INF) {
		stack.Push(ep);//���� push
		int temp = path[ep];
		while (temp != sp) {
			stack.Push(temp);
			temp = path[temp];
		}
		stack.Push(sp);//������ push
		while (!stack.Empty())stack.Pop();
		putchar('\n');
	}
	else {
		printf("��� X\n");
	}
}
int main() {
	int n, m;//n�� ���� ��, m�� ���� ��
	int a, b, c;//a�� ������, b�� ����, c�� ������ ����ġ
	int v;//���� ����
	printf("���� ���� ���� �� �Է� >");
	scanf_s("%d %d", &n, &m);
	Graph g(n);
	for (int i = 0; i < m; i++) {
		printf("%d��° ������ ����ġ �Է�> ", i + 1);
			scanf_s("%d %d %d", &a, &b, &c);
			g.InsertLength(a, b, c);
	}
	printf("���� ���� �Է�> ");
	scanf_s("%d", &v);//������� �Է�

	printf("����ġ�� ���� �������\n");
	g.Matrix();
	printf("���� ����� �迭 dist�� ��\n");
	g.ShortestPath(v);
	g.DistValue();
	printf("�� ���������� �ִ� ���\n");
	for (int i = 0; i < n; i++) {
		if (i != v) {
			printf("���� %d: ", i);
			g.PrintShortestPath(v, i);
		}
	}
	return 0;
}