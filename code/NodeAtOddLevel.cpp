#include<bits/stdc++.h>
using namespace std;
struct Node {
	int data;
	Node *left;
	Node *right;
};
struct Node *getNewNode(int data){
	struct Node *temp = (Node*)malloc(sizeof(Node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
void nodeAtOddLevel(struct Node *root,bool odd){
	if(root == NULL)
		return;
	if(odd)
		cout<<root->data<<" ";
	nodeAtOddLevel(root->left,!odd);
	nodeAtOddLevel(root->right,!odd);		
}
int main(){
	struct Node *root = getNewNode(1);
	root->left = getNewNode(2);
	root->right = getNewNode(3);
	root->left->left = getNewNode(4);
	root->left->right = getNewNode(5);
	root->right->left = getNewNode(6);
	root->right->right = getNewNode(7);
	nodeAtOddLevel(root,true);
}
