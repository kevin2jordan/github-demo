#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node *next;
};
void push(struct Node *&head, int data){
	struct Node *temp = (Node*)malloc(sizeof(Node));
	temp->data = data;
	temp->next = head;
	head = temp;
}

void pushFront(struct Node *&head, int data){
	struct Node *temp =(Node*)malloc(sizeof(Node));
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

}
void reverseList(struct Node *&head){
	struct Node *curr = head, *next = NULL, *prev = NULL;
	while(curr!=NULL){
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	head = prev;
}
void printList(struct Node *head){
	struct Node *temp = head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}
int main(){
	struct Node *head = NULL;
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		int k;
		cin >> k;
		pushFront(head,k);
	}
	printList(head);
	reverseList(head);
	cout<<endl<<endl;
	printList(head);
}
