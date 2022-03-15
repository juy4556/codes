#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> part;
vector <int> inquire;

void binsearch(int start, int end, vector <int> array, int target){
    while(start<=end){
        int mid = (start+end)/2;
        if(array[mid]==target){
            cout<<"yes ";
            return;
        }
        else if(array[mid]>target){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
    cout<<"no ";
    return;
}
int main(){
    int n, m;
    cin >> n;
    int input;
    for(int i=0;i<n;i++){
        cin>>input;
        part.push_back(input);
    }
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>input;
        inquire.push_back(input);
    }
    sort(part.begin(),part.end());
    for(int i=0;i<m;i++){
        binsearch(0,n-1,part,inquire[i]);
    }


    return 0;
}