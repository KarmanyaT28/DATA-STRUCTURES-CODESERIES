//Getting the nth node in a linked list BY ME.
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
		int length();
		int getn(int index);
};

linkedlist::linkedlist(int A[],int n){
	Node *last, *t;
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
	int len=0;
	Node *p=first;
	while(p){
		len++;
		p=p->next;
	}	
	return len;
}


int linkedlist::getn(int index){
	Node *p=first;
	while(p!=NULL){
		if(index<0||index>length())
			return 0;
		if(index==0){
			return p->data;
		}
		else{
			
			for(int i=0;i<index;i++){
				p=p->next;
			}
			return p->data;		}
	}
}

int main(){
	int A[]={1,2,3,4,5};
	linkedlist l(A,5);
	l.display();
	cout<<l.getn(2);
	return 0;
	
}
