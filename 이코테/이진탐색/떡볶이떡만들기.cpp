#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n,m;
vector <int> height;

int binsearch(int start, int end, vector <int> arr, int target){
    int mid_min=0;
    while(start<=end){
        int mid = (start+end)/2;
        int sum = 0;
        for(int i=0;i<n;i++){
            if((arr[i]-mid)>0){
                sum+=(arr[i]-mid);
            }
        }
        if(sum<target){
                end = mid - 1;
            }
            else{
                start = mid + 1;
                mid_min = mid;
            }
    }
    return mid_min;
}
int main(){
    cin>>n>>m;
    int input;
    for (int i=0;i<n;i++){
        cin>>input;
        height.push_back(input);
    }
    sort(height.begin(),height.end());
    cout<<binsearch(0,height[n-1],height,m);
    

    return 0;
}