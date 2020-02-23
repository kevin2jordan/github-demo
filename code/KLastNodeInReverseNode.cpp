#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node *next;
};
void insertBegin(struct Node *&head,int data){
	struct Node *temp = (Node*)malloc(sizeof(Node));
	temp->data = data;
	temp->next = head;
	head = temp;
}
void printList(struct Node *root){
	struct Node *temp = root;
	while(root != NULL){
		cout<<root->data<<" ";
		root = root->next;
	}
}
void insertEnd(struct Node *&head, int data){
	struct Node *temp = (Node*)malloc(sizeof(Node));
	temp->data = data;
	temp->next = NULL;
	if(head == NULL){
		head = temp;
		return;
	}
	struct Node *last = head;
	while(last->next != NULL){
		last = last->next;
	}
	last->next = temp;
	return;
}
int main(){
	struct Node *root = NULL;
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		int k;
		cin >> k;
		insertEnd(root,k);
	}
	printList(root);
}
