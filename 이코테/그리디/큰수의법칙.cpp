#include <iostream>
#include <algorithm>
using namespace std;
int num[1000];

bool cmp(int a, int b){
    return a>b;//내림차순
}
int main(){
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(0);
    int N,M,K;//N은 2이상 1000이하, M과 K는 1이상 10000이하, K는 항상 M이하
    cin>>N>>M>>K;
    for(int i=0;i<N;i++){
        cin>>num[i];//각 자연수는 1이상 10,000이하의 수
    }
    sort(num,num+N,cmp);
    int count=0;
    int result=0;
    for(int i=0;i<M;i++){
        count++;
        if(count<=K)result+=num[0];
        else {
            result+=num[1];
            count=0;
            }
    }
    cout<<result;

    return 0;
}