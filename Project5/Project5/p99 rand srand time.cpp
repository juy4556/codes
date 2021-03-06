#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {
	srand((int)time(NULL));
	for (int i = 0; i < 5; i++) {
		cout<<rand() % 100<<' ';
	}
	return 0;
}