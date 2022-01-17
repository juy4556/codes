#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<string> ::iterator vi;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        string temp;
        int index = 0;
        while (cnt < n) {
            if (arr1[i] % 2 || arr2[i] % 2)
                temp.append("#");
            else temp.append(" ");
            index++;
            cnt++;
            arr1[i] /= 2;
            arr2[i] /= 2;
        }
        reverse(temp.begin(),temp.end());
        answer.push_back(temp);
    }

    return answer;
}

int main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n;//n�� 1�̻� 16����
    cin >> n;
    vector <int> arr1(n);
    vector <int> arr2(n);
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }
    for (int j = 0; j < n; j++) {
        cin >> arr2[j];
    }

    vector<string> sol = solution(n, arr1, arr2);
    for (int i = 0; i < n; i++) {
        cout << sol[i] << '\n';
    }


    return 0;
}