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
		void rdisplay();
		int length();
		int rlength();
		int sum();
		int rsum();
		int max();
		int rmax();
		void insert(int index,int x);
		int Delete(int index);
		
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

void linkedlist::rdisplay(){
	Node *p=first;
	if(p!=NULL){
		rdisplay();
		cout<<p->data;
	}
	cout<<endl;
}

int linkedlist::length(){
	Node *p=first;
	int len=0;
	while(p!=NULL){
		len++;
		p=p->next;
	}
	return len;
}

int linkedlist::rlength(){
	Node *p=first;
	int len=0;
	if(p!=NULL){
		return rlength()+1;
	}
	else{
		return 0;
	}
}

int linkedlist::sum(){
	Node *p=first;
	int sum=0;
	while(p!=NULL){
		sum=sum+p->data;
		p=p->next;
	}
	return sum;
}

int linkedlist::rsum(){
	Node *p=first;
	int sum=0;
	if(p==0){
		return 0;
	}
	else{
		return rsum()+p->data;
	}
}

int linkedlist::max(){
	Node *p=first;
	int max=-10000;
	while(p!=NULL){
		if(p->data>max){
			max=p->data;
			
		}
		p=p->next;
	}
	return max;
}

int linkedlist::rmax(){
	Node *p=first;
	int x=0;
	if(p==0)
		return -10000;
	x=rmax();
	if(x>p->data){
		return x;
	}
	else{
		return p->data;
	}
}

void linkedlist::insert(int index, int x){
	Node *t,*p=first;
	if(index<0||index>length())
		return ;
	t=new Node;
	t->data=x;
	t->next=NULL;
	if(index==0){
		t->next=first;
		first=t;
	}
	else{
		for(int i=0;i<index-1;i++){
			p=p->next;
		}
		t->next=p->next;
		p->next=t;
	}
}


int linkedlist::Delete(int index){
	Node *p,*q=NULL;
	int x=-1;
	if(index<1||index>length())
		return -1;
	if(index==1){
		p=first;
		first=first->next;
		x=p->data;
		delete p;
	}
	else{
		p=first;
		for(int i=0;i<index-1;i++){
			q=p;
			p=p->next;
		}
		q->next=p->next;
		x=p->data;
		delete p;
	}
	return x;
}

int main(){
	int A[]={1,2,3,4,5};
	linkedlist l(A,5);
	l.insert(3,10);
	l.Delete(1);
	l.display();
	
	
	return 0;
}
