//Favourite Number Question 
//Among all the digits from 0-9 , a boy likes number 5 , He has lots of numbers and wants you to find out the number of times 5 occured in each number.


#include<iostream>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int rem , count=0;
		while(n!=0){
			rem=n%10;
			n=n/10;
			if(rem==5){
				count++;
			}
			
		}
		cout<<count<<endl;
		
	}
}
