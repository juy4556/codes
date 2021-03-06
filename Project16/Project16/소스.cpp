#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main() {
	for (int i = 2; i <= 20; i++) {
		cout << setprecision(5) << setw(10) << left;
		cout <<showpos<< log(i)<<' '<<log10(i)<<'\n';
	}
	return 0;
}