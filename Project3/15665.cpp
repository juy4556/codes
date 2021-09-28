#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

void func(int row, int m, int cnt, int size,vector<int> v,int o[]) { 
    if (cnt == m) {
        for (int i = 0; i < m; i++) {
            printf("%d ", v[o[i]]);
        }
        printf("\n");

        return;
    }
    for (int i = 0; i < size; i++) {;
        o[row] = i;
        func(row+1, m, cnt+1, size, v, o);
    }
}

int main() {
    int n, m; //1<=m<=n<=7
    scanf_s("%d %d", &n, &m);
    vector <int> seq;// ������ 10000���� �۰ų� ����
    int value;
    for (int i = 0; i < n; i++) {
        scanf_s("%d", &value);
        seq.push_back(value);
    }
    sort(seq.begin(), seq.end());
    vector <int> v;//seq���� ���� �ٸ� ������ ����
    int* o = new int[8];
    v.push_back(seq[0]);
    for (int i = 1; i < n; i++) {
        while (seq[i] == seq[i - 1]&&i<n-1)i++;
        if(seq[i]!=seq[i-1])
        v.push_back(seq[i]);
    }
    /* unique�Լ��� erase����Ͽ� �ߺ��� ��� ����
    seq.erase(unique(seq.begin(), seq.end()),seq.end());
    */
    /* set �����̳�
    set<int> s;
    set<int>::iterator iter, start, end;
    for (int i = 0; i < seq.size(); i++) {
        s.insert(seq[i]);
    }
    for (iter=s.begin();iter!=s.end();iter++){
        printf("%d", *iter);
    }
    */
    
    int size=v.size();//�������� ���� �ٸ� �� ����
    int cnt=0;
    func(0,m,cnt,size,v,o);

    return 0;
}