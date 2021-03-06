#include <iostream>
#include <cstring>
using namespace std;
int main() {
	int n;
	char name[20];
	char oname[20], yname[20];//늙은이,젊은이 이름
	int date[3];
	int odate[3];//늙다리 생일
	int ydate[3];//젊은이 생일
	cin >> n;
	cin >> name >> date[0] >> date[1] >> date[2];
	if (date[0] < 1)
		return -1;
	else if (date[1] < 1 || date[1]>12)
		return -1;
	else if (date[2] < 1990 || date[2]>2010)
		return -1;
	strcpy_s(oname, name);
	strcpy_s(yname, name);// 늙,젊 이름 첫째줄 이름으로 초기화
	for (int i = 0; i < 3; i++) {
		odate[i] = date[i];
		ydate[i] = date[i];
	}//생일도 
	for (int j = 0; j < n - 1; j++) {
		cin >> name >> date[0] >> date[1] >> date[2];

		if (date[0] < 1)
			return -1;
		else if (date[1] < 1 || date[1]>12)
			return -1;
		else if (date[2] < 1990 || date[2]>2010)
			return -1;

		if (odate[2] < date[2]) {
			strcpy_s(oname, name);
			for (int k = 0; k < 3; k++) {
				odate[k] = date[k];
			}
		}
		else if (odate[2] = date[2]) {
			if (odate[1] < date[1]) {
				strcpy_s(oname, name);
				for (int l = 0; l < 3; l++) {
					odate[l] = date[l];
				}
			}
			else if (odate[1] = date[1] && odate[0] < date[0]) {
				strcpy_s(oname, name);
				for (int m = 0; m < 3; m++) {
					odate[m] = date[m];
				}
			}
		}
		if (ydate[2] > date[2]) {
			strcpy_s(yname, name);
			for (int k = 0; k < 3; k++) {
				ydate[k] = date[k];
			}
		}
		else if (ydate[2] = date[2]) {
			if (ydate[1] > date[1]) {
				strcpy_s(yname, name);
				for (int l = 0; l < 3; l++) {
					ydate[l] = date[l];
				}
			}
			else if (ydate[1] = date[1] && ydate[0] > date[0]) {
				strcpy_s(yname, name);
				for (int m = 0; m < 3; m++) {
					ydate[m] = date[m];
				}
			}
		}
	}
	cout << yname << '\n';
	cout << oname;
	return 0;
}