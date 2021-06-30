#include<iostream>
using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt" , "r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int savings;
    cin>>savings;
     
    if(savings>5000){
        if(savings>10000){
            cout<<"Roadtrip with neha";
        }
        else{
            cout<<"Dinner with neha";
        }
        
    
    }
    else if(savings>2000){
        if(savings>3500){
            cout<<"Lunch with rashmi";
        }
        else{
            cout<<"Icecream with rashmi";
        }
        
    }
    else{
        cout<<"Friends";
    }
}