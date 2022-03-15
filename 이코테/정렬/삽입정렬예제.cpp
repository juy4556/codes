#include <iostream>
#include <vector>
using namespace std;

vector <int> v;
int main(){
    int n;
    cin>>n;
    int num;
    for(int i=0;i<n;i++){
        cin>>num;
        v.push_back(num);
    }
    for(int i=1;i<n;i++){
        for(int j=i;j>0;j--){
            if(v[j]<v[j-1]){//오름차순
                int temp = v[j];
                v[j]=v[j-1];
                v[j-1]=temp;
            }
        }    
    }
    for(int i=0;i<n;i++){
        cout<<v[i]<<' ';
    }
    return 0;
}