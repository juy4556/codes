#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int n,m;//n:가로길이,m:세로길이(둘 다 1이상 1000이하)

bool dfs(int **ice, int x, int y){
    if(x<0 || y<0 || x>=n || y>=m)
        return false;
    if(!ice[x][y]){
        ice[x][y]=1;
        dfs(ice,x-1,y);
        dfs(ice,x+1,y);
        dfs(ice,x,y-1);
        dfs(ice,x,y+1);
        return true;
    }
    return false;
}
int main(){
    int count=0;//생성되는 아이스크림 수
    cin>>n>>m;
    cin.ignore();
    int **ice = new int*[n];
    for(int i=0;i<n;i++){
        ice[i] = new int[m];
    }
    for(int i=0;i<n;i++){
        string tmp;
        getline(cin, tmp);
        for(int j=0;j<m;j++){
            ice[i][j]=tmp[j]-48;
            cout<<ice[i][j]<<' ';
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if (dfs(ice,i,j)){
                count++;
            }
        }
    }

    cout<<count<<'\n';
    for(int i=0;i<n;i++){
        delete[] ice[i];
    }
    delete[] ice;
    return 0;
}