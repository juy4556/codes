#include <iostream>
#include <string>
using namespace std;

int main(){
    string str;
    getline(cin,str);
    if(str[0]=='a'||str[0]=='h'){
        if(str[1]=='1'||str[1]=='8'){
            cout<<2;
        }
        else if(str[1]=='2'||str[1]=='7'){
            cout<<3;
        }
        else{
            cout<<4;
        }
    }
    else if(str[0]=='b'||str[0]=='g'){
        if(str[1]=='1'||str[1]=='8'){
            cout<<3;
        }
        else if(str[1]=='2'||str[1]=='7'){
            cout<<4;
        }
        else{
            cout<<6;
        }
    }
    else{
        if(str[1]=='1'||str[1]=='8'){
            cout<<4;
        }
        else if(str[1]=='2'||str[1]=='7'){
            cout<<6;
        }
        else{
            cout<<8;
        }
    }

    return 0;
}