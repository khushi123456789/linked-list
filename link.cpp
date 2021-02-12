#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct node{
		int data;
		node* next;
};
struct node* h;
void print()
{
 struct node* temp=h;
 	while(temp!=NULL)
	{cout<<temp->data<<" ";
	temp=temp->next;
	}
}
void insert(int data,int pos){
	int k=1;
	node *p,*q,*newnode;
	newnode=new node();
	newnode->data=data;
	p=h;
	if(pos==1)
	{
	newnode->next=p;
	h=newnode;
}
else{
	while((p!=NULL)&&(k<pos)){
		k++;
		q=p;
		p=p->next;}
		q->next=newnode;
		newnode->next=p;
	}
}

int main(){
	int n,pos,x;
	cout<<"enter your position";
	cin>>pos;
	cout<<"enter the n";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"enter data";
		cin>>x;
	insert(x,pos);
	print();
}
	return 0;
}

