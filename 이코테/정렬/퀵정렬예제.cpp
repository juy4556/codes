#include <iostream>
using namespace std;
int arr[]={5,2,1,3,9,6,4,7,8};

void quick_sort(int* arr, int start, int end){
    if(start>=end) return; // 원소 하나면 리턴
    int pivot = start;
    int left = start+1;
    int right = end;
    while(left<=right){
        while(left<=end && arr[pivot] >= arr[left])
            left++;
        while(right>start && arr[pivot] <= arr[right])
            right--;
        if(left>=right){
            int temp;
            temp = arr[pivot];
            arr[pivot] = arr[right];
            arr[right] = temp;
        }
        else{
            int temp;
            temp = arr[left];
            arr[left]=arr[right];
            arr[right]=temp;
        }
    }
    quick_sort(arr,start,right-1);
    quick_sort(arr,right+1,end);
}

int main(){
    for(int i=0;i<sizeof(arr)/sizeof(int);i++){
        cout<<arr[i]<<" ";
    }
    quick_sort(arr,0,sizeof(arr)/sizeof(int)-1);
    cout<<'\n';
    for(int i=0;i<sizeof(arr)/sizeof(int);i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}