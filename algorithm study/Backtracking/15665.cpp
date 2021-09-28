#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
//    func(0,m,cnt,size,v,o);

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
    vector <int> seq;// 수들은 10000보다 작거나 같음
    int value;
    for (int i = 0; i < n; i++) {
        scanf_s("%d", &value);
        seq.push_back(value);
    }
    sort(seq.begin(), seq.end());
    vector <int> v;//seq에서 서로 다른 수들의 집합
    int* o = new int[8];
    v.push_back(seq[0]);
    for (int i = 1; i < n; i++) {
        while (seq[i] == seq[i - 1]&&i<n-1)i++;
        if(seq[i]!=seq[i-1])
        v.push_back(seq[i]);
    }
    /* unique함수와 erase사용하여 중복된 요소 삭제
    seq.erase(unique(seq.begin(), seq.end()),seq.end());
    */
    /* set 컨테이너
    set<int> s;
    set<int>::iterator iter, start, end;
    for (int i = 0; i < seq.size(); i++) {
        s.insert(seq[i]);
    }
    for (iter=s.begin();iter!=s.end();iter++){
        printf("%d", *iter);
    }
    */
    
    int size=v.size();//수열에서 서로 다른 수 갯수
    int cnt=0;
    func(0,m,cnt,size,v,o);

    return 0;
}