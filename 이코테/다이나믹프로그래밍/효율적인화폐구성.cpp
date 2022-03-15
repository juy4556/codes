#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> arr;
vector <int> d;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    int num;
    for(int i=0;i<n;i++){
        cin>>num;
        arr.push_back(num);
    }
    for(int i=0;i<m+1;i++){
        d.push_back(10001);
    }
    d[0]=0;
    for(int i=0;i<n;i++){
        for(int j=arr[i];j<m+1;j++){
            d[j] = min(d[j],d[j-arr[i]]+1);
        }
    }
    if(d[m]==10001){
        cout<<"-1";
    }
    else{
    cout<<d[m];
    }

    return 0;
}