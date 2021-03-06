#include <iostream>
#include <cstring>
using namespace std;

struct student {
	char id[10];
	char name[10];
	char major[10];
	char address[30];
	float gpa;
	char bdate[11];
};
struct course {
	char id[10];
	char name[20];
	char instructor[10];
	char prerequisite[10];
};
struct course_taken {
	char sid[10];
	char cid[10];
	float grade;
	int year_taken;
};
int main() {
	int i, j, k;
	int n1,n2,n3;
	cin >> n1;
	student* s = new student[n1];
	
	for (i = 0; i < n1; i++) {
		cout << i + 1 << "번째 학생 데이터 입력" << endl;
		cin >> s[i].id >> s[i].name >> s[i].major >> s[i].address >> s[i].gpa >> s[i].bdate;
	}
	cin >> n2;
	course* c = new course[n2];
	for (j = 0; j < n2; j++) {
		cout << j + 1 << "번째 강의 데이터 입력" << endl;
		cin >> c[j].id >> c[j].name >> c[j].instructor >> c[j].prerequisite;
	}
	cin >> n3;
	course_taken* ct = new course_taken[n3];
	for (k = 0; k < n3; k++) {
		cout << k + 1 << "번째 수강 데이터 입력" << endl;
		cin >> ct[k].sid >> ct[k].cid >> ct[k].grade >> ct[k].year_taken;
	}
	for (i = 0; i < n1; i++) {
		cout << s[i].name <<' ';
		for (j = 0; j < n2; j++) {
			for (k = 0; k < n3; k++) {
				if (!strcmp(c[j].id, ct[k].cid)&&!strcmp(s[i].id,ct[k].sid)) {
					cout << c[j].name << ' ';
					cout << ct[k].grade << endl;
				}
			}
		}
	}
	delete[]s;
	delete[]c;
	delete[]ct;
	return 0;
}