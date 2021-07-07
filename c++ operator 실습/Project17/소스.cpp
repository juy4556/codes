#include <iostream>
using namespace std;

class box {
private:
	double l, w, h;
public:
	box(double a, double b, double c) :l(a), w(b), h(c) {}
	box():l(0),w(0),h(0){}
	void vol() {
		cout << "ºÎÇÇ: " << l * w * h << "\n";
	}
	friend box add_box(box a, box b);
	box operator*(box b);
};
box add_box(box a,box b){
	box temp;
	temp.l = a.l + b.l;
	temp.w = a.w + b.w;
	temp.h = a.h + b.h;
	return temp;
}
box box::operator*(box b) {
	l *= b.l;
	w *= b.w;
	h *= b.h;
	return *this;
}
int main() {
	box x(3.0, 2.0, 1.0), y(1.0, 2.0, 3.0), z;
	z = add_box(x, y); z.vol();
	z = x * y; z.vol();
	return 0;
}