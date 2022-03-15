#include<iostream>
#define MAX_VALUE 9
using namespace std;
int arr[]={5,2,1,3,9,6,4,7,8,2,3,4,1,1};

int main(){
    int*count = new int[MAX_VALUE+1];
    for(int i=0;i<=MAX_VALUE;i++){
        count[i]=0;
    }
    for(int i=0;i<sizeof(arr)/sizeof(int);i++){
        count[arr[i]]++;
    }
    for(int i=0;i<=MAX_VALUE;i++){
        for(int j=0;j<count[i];j++){
            cout<<i<<' ';
        }
    }

    delete[]count;
    return 0;
}