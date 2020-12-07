//Insert In A Sorted Linked List

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
		void sortedinsert(int x);
		
};

linkedlist::linkedlist(int A[],int n){
	Node *last,*t;
	int i=0;
	
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

void linkedlist::sortedinsert(int x){
	Node *p=first;
	Node *t,*q=NULL;
	t=new Node;
	t->data=x;
	t->next=NULL;
	
	if(first==NULL){
		first=t;
	}
	else{
		while(p && p->data<x){
			q=p;
			p=p->next;
		}
		if(p==first){
			t->next=first;
			first=t;
		}
		else{
			t->next=q->next;
			q->next=t;
		}
	}
	
	
}


int main(){
	int A[]={1,2,4,5,6,7,8};
	linkedlist l(A,7);
	cout<<"Enter the number you want to insert"<<endl;
	int x;cin>>x;
	l.sortedinsert(x);
	l.display();
	
	return 0;
	
}
