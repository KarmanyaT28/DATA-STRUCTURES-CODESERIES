#include<iostream>
using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif


    int a;
    if(a%2==0){
        cout<<"EVEN";
    }
    else{
        cout<<"ODD";
    }
    return 0;
}