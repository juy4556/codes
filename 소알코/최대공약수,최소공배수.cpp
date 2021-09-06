#include <iostream>
using namespace std;

int GCD(int a,int b);
int LCM(int a, int b);
int main(){
    int a,b;
    int gcd;//최대공약수(great common divisor)
    int lcm;//최소공배수(least common multiple)
    scanf("%d %d",&a,&b);
    //유클리드 호제법
    gcd=GCD(a,b);
    lcm=(a*b)/gcd;
    printf("gcd:%d, lcm:%d",gcd,lcm);
    return 0;
}

int GCD(int a, int b){
    int c;
    while(b){
        c= a%b;
        a=b;
        b=c;
    }
    return a;
}

