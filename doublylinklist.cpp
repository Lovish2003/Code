#include<iostream>
using namespace std;
class node{
	public:
	int data;
	node*next;
	node*prev;
	node(int data){
		this->data=data;
		this->next=NULL;
		this->prev=NULL;
	}
};
void InsertAtHead(int d,node*&head){
	node *temp=new node(d);
	temp->next=head;
	head->prev=temp;
	head=temp;
}
void InsertAtTail(int d,node*&tail){
	node *temp=new node(d);
	tail->next=temp;
	temp->prev=tail;
	tail=tail->next;
}
void InsertAtPosition(node*&head,node*&tail,int position,int d){
	if(head==NULL){
		node *temp=new node(d);
		head=temp;
	}
	if(position==1){
		InsertAtHead(d,head);
		return;
	}
	node*temp=head;
	int cnt=1;
	while(cnt<position-1){
		temp=temp->next;
		cnt++;
	}
	if(temp->next==NULL){
		InsertAtTail(d,tail);
		return;
	}
	node *nodeToInsert=new node(d);
	nodeToInsert->next=temp->next;
	temp->next->prev=nodeToInsert;
	temp->next=nodeToInsert;
	nodeToInsert->prev=temp;
}
void deleteNode(node*&head,int position){
	if(position==1){
		node*temp=head;
		temp->next->prev=NULL;
		head=temp->next;
		temp->next=NULL;
		delete temp;
	}
	else{
		node *curr=head;
		node *previous=NULL;
		int cnt=1;
		while(cnt<=position){
			previous=curr;
			curr=curr->next;
			cnt++;
		}
	curr->prev=NULL;
	previous->next=curr->next;
	curr->next=NULL;
		delete curr;
	}
}
void print(node*&head){
	node*temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}
int main(){
	node *node1=new node(10);
	node *head=node1;
	InsertAtHead(5,head);
	print(head);
	node *tail=node1;
	InsertAtTail(15,tail);
	print(head);
	InsertAtPosition(head,tail,3,13);
	print(head);
	deleteNode(head,2);
	print(head);
}
