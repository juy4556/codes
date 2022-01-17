#include <iostream>
#include <string>
using namespace std;

int main(){
    int N;//공간의 크기 N X N
    string move;//이동계획 L,R,U,D
    cin>>N;
    cin.ignore();
    int x=1,y=1;//x와 y범위는 1이상 N이하
    getline(cin,move);
    for(int i=0;i<move.length();i+=2){
        if(move[i]=='L' && y>1)y--;
        else if(move[i]=='R' && y<5)y++;
        else if(move[i]=='U' && x>1)x--;
        else if(move[i]=='D' && x<5)x++;
    }
    cout<<x<<' '<<y;
    return 0;
}