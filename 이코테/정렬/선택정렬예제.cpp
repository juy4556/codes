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
    for(int i=0;i<n-1;i++){
        for(int j=i;j<n;j++){
            int min_index = i;
            if(v[min_index]>v[j]){ //오름차순
                min_index=j;
            }
            int temp = v[i];
            v[i]=v[min_index];
            v[min_index]=temp;
        }
    }
    for(int i=0;i<n;i++){
        cout<<v[i]<<' ';
    }
    return 0;
}