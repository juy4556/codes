#include <iostream>
#include <string>
#include <queue>
using namespace std;

int n,m;
//상하좌우
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
queue <pair<int,int>> q;
int bfs(int **graph, int x, int y){
    q.push({x, y});
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        cout<<"x:"<<x<<"y:"<<y<<'\n';
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<0 || ny<0 || nx>=n || ny>=m)
                continue;
            if (graph[nx][ny] == 0){
                continue;
            }
            if (graph[nx][ny] == 1){
                graph[nx][ny] = graph[x][y] + 1;
                q.push({nx,ny});
            }
        }
        if(x==4 && y==5)break;
    }
    return graph[n-1][m-1];
}

int main(){
    cin>>n>>m;
    cin.ignore();
    int **monster = new int*[n];
    for(int i=0;i<n;i++){
        monster[i] = new int[m];
    }
    for(int i=0;i<n;i++){
        string tmp;
        getline(cin, tmp);
        for(int j=0;j<m;j++){
            monster[i][j]=tmp[j]-48;
            cout<<monster[i][j]<<' ';
        }
        cout<<'\n';
    }

    cout<<bfs(monster,0,0);
    for(int i=0;i<n;i++){
        delete[] monster[i];
    }
    delete[] monster;
    return 0;
}