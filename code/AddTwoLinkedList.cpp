#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node *next;
};
void insert(struct Node *&head, int data){
	struct Node *temp = (Node*)malloc(sizeof(Node));
	temp->data = data;
	temp->next = head;
	head = temp;
}
void printList(struct Node *head){
	while(head!=NULL){
		cout<<head->data<<" ";
		head = head->next;
	}
}
void addLinkedList(struct Node *head1, struct Node *head2){
	int carry =0, sum = 0;
	struct Node *root = NULL;
	while(head1 != NULL || head2 != NULL){
		int x = head1?head1->data:0;
		int y = head2?head2->data:0;
		cout<<x<<" "<<y<<" "<<carry<<endl;
		int temp = x+y;
		sum = temp%10 + carry;
		insert(root,sum);
		carry = temp/10;
		if(head1)
			head1 = head1->next;
		if(head2)	
		head2 = head2->next;
	}
//	cout<<"Output is \n";
	while(root!=NULL){
		cout<<root->data<<" ";
		root = root->next;
	}

}
int main(){
	struct Node *head = NULL;
	int n,k;
	cout<<"First number ";
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> k;
		insert(head,k);
	}
	cout<<"Second number ";
	int m;
	cin >> m;
	struct Node *head1 = NULL;
	for(int i=0;i<m;i++){
		cin >> k;
		insert(head1,k);
	}
	cout<<"Sum is \n";
	addLinkedList(head,head1);
}
