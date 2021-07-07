/*백준1936(재미있는 수학 문제)
f(n,k)가 p로 나누어 떨어지지 않는 k(0<=k<=n)의 수 구하기
첫째 줄 정수 n과 소수 p 주어짐
문제 조건을 만족하는 k의 개수를 (10^9+7)로 나눈 나머지 출력*/
#include <iostream>
using namespace std;

int main(){
unsigned long long n;
int p;
scanf_s("%lld %d",&n,&p);
int count = n;
//f(n,1)=n(n+2)/2
if(n==2&&p==2)count--;
else if(p==n || p==n+1)count--;
//f(n,2)=n(n-1)(n+1)(3n+2)/24
if(p==n || p==n-1 || p==n+1 || p==(3*n+2))count--;
//f(n,3)

//f(n,n-1)=(n-1)!*...
if(p<n)count--;
//f(n,n)=n!
if(p<=n)count--;

    return 0;
}