#include <iostream>
using namespace std;

int main(){
    int N;//0이상 23이하
    cin>>N;
    int count = 0;
    for(int h=0;h<=N;h++){
        for(int m=0;m<60;m++){
            for(int s=0;s<60;s++){
                if(h%10==3 || m/10==3 || m%10==3 || s/10==3 || s%10 ==3)
                count++;
            }
        }
    }
    cout<<count;
    return 0;
}