//Now Check If your Linked List Is Sorted OR NOT!!
#include<iostream>
using namespace std;
class Node
{
	public:
		int data;
		Node *next;
};

class linkedlist
{
	private:
		Node *first;
	public:
		linkedlist()
		{
			first=NULL;
		}
		linkedlist(int A[],int n);
		~linkedlist();
		
		void display();
		int isSorted();
};

linkedlist::linkedlist(int A[],int n)
{
	Node *t,*last;
	int i=0;
	first=new Node;
	first->data=A[0];
	first->next=NULL;
	last=first;
	
	for(i=1;i<n;i++){
		t = new Node;
		t->data=A[i];
		t->next=NULL;
		last->next=t;
		last=t;
	}
}

linkedlist::~linkedlist()
{
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

int linkedlist::isSorted(){
	Node *p=first;
	int x=-65536;
	while(p!=NULL){
		if(p->data<x)
			return 0;
		x=p->data;
		p=p->next;
		
	}
	return 1;
	
}

int main(){
	int A[]={1,2,3,7,5,4};
	linkedlist l(A,6);
	
	cout<<l.isSorted();
	
	return 0;
}
