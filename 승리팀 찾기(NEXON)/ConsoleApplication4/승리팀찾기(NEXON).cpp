#include <iostream>
#include <cstring>

using namespace std;

int main() {
	int t;// 케이스 수
	char kind[6];//게임 종류
	char team[5];//RED OR BLUE 팀
	char steam[8][5];
	int blue = 0, red = 0;
	int m;
	int ss;
	int xx;
	char win[100][5];
	int min=36000;//time<36000
	int max = 0;
	int sectime[8];
	int temp=0;
	string str;
	int index=0;
	int score[8] = { 10,8,6,5,4,3,2,1 };
	int bluesum = 0;
	int redsum = 0;
	cin >> t;//케이스 수 입력
	for (int i = 0; i < t; i++) {
		cin >> kind;//게임 종류 입력
		cin.ignore();
		if (strcmp(kind,"item")==0) {//게임 종류 아이템전일 때
			blue = 0, red = 0;
			while ((blue+red)<8) {
				cin >> team;//red or blue 팀 입력
				if (strcmp(team,"blue")==0)
					blue++;
				else if (strcmp(team,"red")==0)
					red++;
				scanf_s("%d:%d.%d", &m, &ss, &xx);
				if (min > m * 3600 + ss * 60 + xx) {
					min = m * 3600 + ss * 60 + xx;
					strcpy_s(win[i], team);
				}
			}
		}
		else if (strcmp(kind, "speed") == 0) {//스피드전일 때
			blue=0,red=0;
			int a = 0;
			while ((blue + red) < 8) {
				cin >> steam[a];
				if (strcmp(steam[a], "blue") == 0)
					blue++;
				else if (strcmp(steam[a], "red") == 0)
					red++;
				scanf_s("%d:%d.%d", &m, &ss, &xx);
				sectime[a] = m * 3600 + ss * 60 + xx;
				if (min > m * 3600 + ss * 60 + xx) {
					min = m * 3600 + ss * 60 + xx;
				}
				a++;
			}
			for (int i = 0; i < 7; i++) {
				if (sectime[i] > min + 600)//리타이어
					sectime[i] = 36000;
			}
			for (int i = 0; i < 7; i++) {
				for (int j = i + 1; j < 8; j++) {
					if (sectime[i] > sectime[j]) {
						temp = sectime[i];
						sectime[i] = sectime[j];
						sectime[j] = temp;//빠른순서로(작은 수 앞)
						if (strcmp(steam[i], steam[j]) != 0) {
							str = steam[i];
							strcpy_s(steam[i], steam[j]);
							strcpy_s(steam[j], steam[i]);//팀도
						}
					}
				}
				if (sectime[i] == 36000) {
					index = i;//리타
					break;
				}
			}

			for (int k = 0; k < index; k++) {
				if (strcmp(steam[k], "red") == 0) {
					redsum += score[k];
				}
				else
					bluesum += score[k];
			}
			if (redsum > bluesum) {
				strcpy_s(win[i], "red");
			}
			else {
				strcpy_s(win[i], "blue");
			}
		}
	}
	for (int i = 0; i < t; i++) {
		cout << win[i] << '\n';
	}
	return 0;
}