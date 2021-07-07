#include <iostream>
using namespace std;

typedef struct __Point {
	int xpos;
	int ypos;
}Point;

Point& PntAdder(const Point& p1, const Point& p2) {
	Point* c = new Point;
	c->xpos= p1.xpos + p2.xpos;
	c->ypos= p1.ypos + p2.ypos;
	return *c;
}
int main() {
	Point* a = new Point;
	Point* b = new Point;
	a->xpos = 1;
	a->ypos = 2;
	b->xpos = 3;
	b->ypos = 4;
	Point &ref =PntAdder(*a, *b);
	cout << ref.xpos << ' ' << ref.ypos << endl;
	delete a;
	delete b;
	delete &ref;
	return 0;
}