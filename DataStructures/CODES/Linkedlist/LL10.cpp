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
		linkedlist(int A[],int n);
		~linkedlist();
		void display();
		void reverse();
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
	while(p!=NULL){
		cout<<p->data;
		p=p->next;
	}
	cout<<endl;
}

void linkedlist::reverse(){
	Node *p=first;
	Node *q=NULL,*r=NULL;
	while(p!=NULL){
		r=q;
		q=p;
		p=p->next;
		q->next=r;
	}
	first=q;
}


int main(){
	int A[]={10,20,30,40,50,60};
	linkedlist l(A,6);
	l.reverse();
	l.display();
	
	
	return 0;
}


