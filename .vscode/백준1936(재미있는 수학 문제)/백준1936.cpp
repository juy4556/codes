#include <iostream>
using namespace std;

int main(){
unsigned long long n;
int p;
int count = 1;//f(n,0)=1
scanf_s("%lld %d",&n,&p);
//f(n,1)=n(n+2)/2
if(p==2)count++;
else if(p==n || p==n+1)count++;
//f(n,2)=n(n-1)(n+1)(3n+2)/24
count++;
if(p==n || p==n-1 || p==n+1 || p==3n+2)count--;
if(p>n)count++;//f(n,n)=n!

    return 0;
}