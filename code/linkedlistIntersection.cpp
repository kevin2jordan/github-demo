#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node *next;
};
void printList(struct Node *head){
	struct Node *temp = head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp =temp->next;
	}
}
int getCount(struct Node *head){
	struct Node *temp = head;
	int cnt=0;
	while(temp != NULL){
		temp = temp->next;
		cnt++;
	}
	return cnt;
}
int getCommonPoint(struct Node *head1, struct Node *head2){
	while(head1!=NULL || head2 != NULL){
		if(head1->data == head2->data)
			return head1->data;
		head1 = head1->next;
		head2 = head2->next;	
	}
	return -1;
}
int getIntersectionPoint(struct Node *head1, struct Node *head2){
	int cnt1 = getCount(head1);
	int cnt2 = getCount(head2);
	int ch=0;
	if(cnt1 > cnt2){
		ch=1;
	}else ch=2;
	if(ch==1){
		int i=0;
		while(i<(cnt1-cnt2)){
			i++;
			head1 = head1->next;
		}
	}
	else if(ch==2){
		int j=0;
		while(j<cnt2-cnt1){
			j++;
			head2 = head2->next;
		}
	}
	
//	printList(head1);
//	cout<<endl<<endl;
//	printList(head2);
	return  getCommonPoint(head1,head2);
}
int main(){
	
	  struct Node* newNode; 
	  struct Node* head1 = 
	            (struct Node*) malloc(sizeof(struct Node)); 
	  head1->data  = 10; 
	  
	  struct Node* head2 = 
	            (struct Node*) malloc(sizeof(struct Node)); 
	  head2->data  = 3; 
	  
	  newNode = (struct Node*) malloc (sizeof(struct Node)); 
	  newNode->data = 6; 
	  head2->next = newNode; 
	  
	  newNode = (struct Node*) malloc (sizeof(struct Node)); 
	  newNode->data = 9; 
	  head2->next->next = newNode; 
	  
	  newNode = (struct Node*) malloc (sizeof(struct Node)); 
	  newNode->data = 15; 
	  head1->next = newNode; 
	  head2->next->next->next  = newNode; 
	  
	  newNode = (struct Node*) malloc (sizeof(struct Node)); 
	  newNode->data = 30; 
	  head1->next->next= newNode; 
	  
	  head1->next->next->next = NULL; 
 
	  
	  cout<<getIntersectionPoint(head1,head2)<<endl;
  
}
