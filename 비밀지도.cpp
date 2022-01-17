#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<string> :: iterator vi;
    for(int i=0;i<n;i++){
        int cnt=0;
        string temp;
        while(cnt<n){
            if(arr1[i]%2 || arr2[i]%2)
                temp[i]='#';
            else temp[i]=' ';

            cnt++;
            arr1[i]/=2;
            arr2[i]/=2;
        }
        answer.push_back(temp);
    }
    
    return answer;
}

int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n;//n은 1이상 16이하
    cin>>n;
    vector <int> arr1(n);
    vector <int> arr2(n);
    for(int i=0;i<n;i++){
        cin>>arr1[i];
    }
    for(int j=0;j<n;j++){
        cin>>arr2[j];
    }
    
    vector<string> sol = solution(n,arr1,arr2);
    for(int i=0;i<n;i++){
        cout<<sol[i]<<'\n';
    }
    
    
    return 0;
}