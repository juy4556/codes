/*
성권이는 Heroes of the Storm 프로게이머 지망생이다.

이 게임에는 총 N개의 캐릭터가 있다. 그리고 현재 각 캐릭터의 레벨은 Xi이다. 성권이는 앞으로 게임이 끝날 때까지, 레벨을 최대 총합 K만큼 올릴 수 있다.

팀 목표레벨 T =min(Xi) (1 ≤ i ≤ N)라고 정의하면, 게임이 끝날 때까지 성권이가 달성할 수 있는 최대 팀 목표레벨 T는 무엇인가?

예를 들어, N = 3, X1= 10, X2= 20, X3= 15이고 K = 10일 때, X1을 7만큼 올리고 X3을 2만큼 올리면 최소 레벨 Xi는 17이 된다. 따라서 팀 목표레벨 T는 17이다. 이 경우처럼 레벨을 총합 K보다 적게 올릴 수도 있다.
*/
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    long long n, k;//n은 캐릭터 수, k는 올릴 수 있는 레벨 총합
    scanf("%lld %lld", &n, &k);
    long long* character = new long long[n];
    for (int i = 0; i < n; i++) {
        scanf("%lld", &character[i]);
    }

    sort(character, character + n);

    long long min, num, dif, ans;

    while (1) {
        min = character[0];
        //num은 min값에 해당하는 수의 개수
        num = upper_bound(character, character + n, min) - character;
        // num = upper_bound(character, character + n, min) - lower_bound(character, character+n,min);했을 시 틀림
        /*printf("upper:%lld\n", *upper_bound(character, character + n, min));
        printf("lower:%lld\n", *lower_bound(character, character + n, min));
        printf("upper-lower:%lld\n", upper_bound(character, character + n, min) - lower_bound(character, character + n, min));
        printf("호잇:%lld\n", upper_bound(character, character + n, min) - character);
        printf("num:%lld\n", num);
        */
        dif = (character[num] - min) * num;
        if (dif <= k) {
            character[0] += dif / num;
        }
        else {
            ans = min + k / num;
            break;
        }
        k -= dif;
    }
    printf("%lld\n", ans);
    delete[]character;
    return 0;
}
