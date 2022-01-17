#include <iostream>
using namespace std;
int num[10001];
int main(){
    cin.tie(0);cout.tie(0);
    ios_base::sync_with_stdio(0);
    int N,M;// N,M은 1이상 100이하
    cin>>N>>M;
    for(int i=0;i<N*M;i++) cin>>num[i]; //1이상 10,000이하
    int min=10001;
    int result=0;//최소값 중 최대

    for(int i=0;i<N;i++){
        min=num[M*i];
        for(int j=1;j<M;j++){
            if(min>num[M*i+j])
            min=num[M*i+j];
        }
        if(result<min)result=min;
    }

    cout<<result;
    return 0;
}