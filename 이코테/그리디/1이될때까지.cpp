#include <iostream>

using namespace std;

int main(){
    int N,K;// N(2<= N <= 100000)과 K(2 <= K <= 100000)이고 둘 다 자연수, N>=K
    cin>>N>>K;
    int count=0;
    while(1){
        if(N%K == 0){
            N=N/K;
            count++;
        }
        else{
            N--;
            count++;
        }
        if(N==1)break;
    }
    cout<<count;
    return 0;
}