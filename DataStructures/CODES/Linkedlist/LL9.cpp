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
		void remdup();
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
void linkedlist::remdup(){
	Node *p=first;
	Node *q=p->next;
	
	while(q!=NULL){
		if(p->data!=q->data){
			p=q;
			q=q->next;
		}
		else{
			p->next=q->next;
			delete(q);
			q=p->next;
		}
	}
}

int main(){
	int A[]={1,2,3,3,4,4,5,5};
	linkedlist l(A,8);
	cout<<"The original linked list is:"<<endl;
	l.display();
	l.remdup();
	cout<<"The linked list after removing all the duplicates!!"<<endl;
	l.display();
	
	return 0;
}


