#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
//점 a->b b->a 간선 weight
vector<pair<int,int>> point[5001];
bool visited[5001];

int main(){
    int N,Q;//N은 영상 개수, Q는 질문
    scanf("%d %d",&N,&Q);
    int p,q,r;//동영상 p,q, r은 weight
    for(int i=0;i<N-1;i++){
        scanf("%d %d %d",&p,&q,&r);
        point[p].push_back({q,r});
        point[q].push_back({p,r});
    }
    int k,v;
    for(int i=0;i<Q;i++){
        scanf("%d %d",&k,&v);
        memset(visited,false,sizeof(visited));
        visited[v] = true;
        int cnt=0;
        queue<int> q;
        q.push(v);
        while(!q.empty()){
            int now = q.front();
            q.pop();
            for(int i=0;i<point[now].size();i++){
                int next=point[now][i].first;//next point
                int weight=point[now][i].second;
                if(visited[next])continue;
                if(weight>=k){
                    cnt++;
                    visited[next]=true;
                    q.push(next);
                }
            }
        }
        cout<<cnt<<'\n';
    }

    return 0;
}