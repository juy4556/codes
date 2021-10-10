#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
vector<int> circle;
vector<int> line[1001];
using namespace std;

void dfs(int ){
}
int main(){
    bool flag;
    int T;//테스트 케이스 수
    scanf("%d",&T);
    int n,m;//n은 동그라미 수, m은 직선 수
    scanf("%d %d",&n,&m);
    circle = vector<int>(n+1);//0초기화
    for(int t=0;t<T;t++){
        for(int i=0;i<m;i++){
            int x,y;
            scanf("%d %d",&x,&y);
            line[x].push_back(y);//한 정점과 연결된 정점 번호 push
            line[y].push_back(x);
        }
        flag=true;
        for(int i=1;i<=n;i++){
            if(!circle[i]){
                circle[i]=1;
                dfs(i);
            }
        }
    }

    return 0;
}