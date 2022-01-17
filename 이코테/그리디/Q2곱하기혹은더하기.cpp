#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    string S;
    const char* str= S.c_str();
    cin>>S;
    int tmp=str[0]-48;
    for(int i=1;i<S.length();i++){
        int num=str[i]-'0';
        if(tmp<=1||num<=1)tmp+=num;
        else tmp*=num;
    }
    cout<<tmp;

    return 0;
}