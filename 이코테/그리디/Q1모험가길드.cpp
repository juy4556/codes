#include <iostream>
#include <algorithm>
using namespace std;
int arr[100001];//최대 모험가 수:100000, 모험가의 공포도 -> arr
int main(){
    int N;//모험가 수 입력
    int count=0;//그룹 내 사람 수
    int group=0;//여행을 떠나는 그룹 수
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&arr[i]);
    }
    sort(arr,arr+N);
    for(int i=0;i<N;i++){
        count++;
        if(count>=arr[i]){
            group++;
            count=0;
        }
    }
    cout << group<<'\n';

    return 0;
}