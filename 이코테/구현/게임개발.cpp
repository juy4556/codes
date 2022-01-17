#include <iostream>

using namespace std;

//n: 세로, m:가로, a:북쪽으로부터 떨어진 칸의 수, b: 서쪽으로부터 떨어진 칸의 수
int n,m,a,b,direction;//3<=n,m<=50
int space[50][50];
int visited[50][50]={0};
int dx[]={-1,0,1,0};//북동남서 방향에 대한 값 정의
int dy[]={0,1,0,-1};


void turn_left(){  
    direction-=1;
    if(direction==-1)direction=3;
}

int main(){
    cin >> n >> m;
    cin >> a >> b >> direction;
    visited[a][b] = 1;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>space[i][j];//육지는 0,바다는 1
        }
    }

    int count = 1;//처음 위치한 공간 카운트하기 때문에 1로 초기화
    int turn_count=0;
    while(1){
        turn_left();
        int na = a + dx[direction];
        int nb = b + dy[direction];
        if(visited[na][nb]==0 && space[na][nb]==0){
            a=na; b=nb;
            count++;
            visited[na][nb]=1;
            turn_count=0;
        }
        else turn_count++;

        if(turn_count==4){
            na=a-dx[direction];
            nb=b-dy[direction];
            if(space[na][nb]==0){
                a=na;b=nb;
                visited[na][nb]=1;
            }
            else break;//바다인경우
            turn_count=0;
        }
    }
    
    cout<<count<<'\n';
    return 0;
}