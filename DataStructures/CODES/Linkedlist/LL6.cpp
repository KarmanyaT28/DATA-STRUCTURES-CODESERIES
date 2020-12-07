#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node *next;
};

class linkedlist{
	private:
		Node *first;
	public:
		linkedlist(){
			
			first=NULL;
		}
		linkedlist(int A[], int n);
		~linkedlist();
		void display();
		bool search(int value);
		int length();
		
};

linkedlist::linkedlist(int A[],int n){
	Node *t,*last;
	int i;
	
	first=new Node;
	first->data=A[0];
	first->next=NULL;
	last=first;
	
	for(i=1;i<n;i++){
		t=new Node;
		t->data=A[i];
		t->next=NULL;
		last->next=t;
		last=t;
	}
}

linkedlist::~linkedlist(){
	Node *p=first;
	while(first){
		first=first->next;
		delete p;
		p=first;
	}
}
void linkedlist::display(){
	Node *p=first;
	while(p){
		cout<<p->data;
		p=p->next;
		
	}
	cout<<endl;
}
int linkedlist::length(){
	Node *p=first;
	int len=0;
	while(p){
		len++;
		p=p->next;
	}
	return len;
}

bool linkedlist::search(int value){
	Node *p=first;
	while(p!=NULL){
		if(value==p->data){
			return true;
		}
		p=p->next;
		
	}
	return false;
}

int main(){
	Node *first=NULL;
	int A[]={1,2,3,4,5,6};
	linkedlist l(A,6);
	int value;	
	cout<<"Enter the value you want the compiler to search:"<<endl;
	cin>>value;
//	l.display();
	l.search(value)?cout<<"Yes":cout<<"No";
	
	
	
	
	
	
	
}
