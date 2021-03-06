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
	int n1, n2, n3;
	cin >> n1;
	student* s = new student[n1];
	for (i = 0; i < n1; i++) {
		cout << i + 1 << "��° �л� ������ �Է�" << endl;
		cin >> s[i].id >> s[i].name >> s[i].major >> s[i].address >> s[i].gpa >> s[i].bdate;
	}// �л� ����ü ������ �Է�
	cin >> n2;
	course* c = new course[n2];
	for (j = 0; j < n2; j++) {
		cout << j + 1 << "��° ���� ������ �Է�" << endl;
		cin >> c[j].id >> c[j].name >> c[j].instructor >> c[j].prerequisite;
	}// ���� ����ü ������ �Է�
	cin >> n3;
	course_taken* ct = new course_taken[n3];
	for (k = 0; k < n3; k++) {
		cout << k + 1 << "��° ���� ������ �Է�" << endl;
		cin >> ct[k].sid >> ct[k].cid >> ct[k].grade >> ct[k].year_taken;
	}// ���� ����ü ������ �Է�
	if (n3 == 0)//���� ����ü�� 0 �̸� ���� �ȴ�
		return -1;
	for (i = 0; i < n1; i++) {
		cout << s[i].name << ' ';
		for (j = 0;j < n3; j++) {
			if (!strcmp(s[i].id, ct[j].sid)) {//�������̺���sid�� �л����̺�id�� �ܷ�Ű(���ƾ���)
				cout << ct[j].cid << ' ';
				cout << ct[j].grade << endl;
			}
		}
	}
	delete[]s;
	delete[]c;
	delete[]ct;
	return 0;
}