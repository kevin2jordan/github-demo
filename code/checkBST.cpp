#include<bits/stdc++.h>
using namespace std;
struct Node{
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
bool checkBSTUtil(struct Node *root, int min, int max){
	if(root == NULL)
		return true;
	if(root->data < min || root->data > max)
		return false;
	return 	checkBSTUtil(root->left,min,root->data - 1) &&
		checkBSTUtil(root->right,root->data+1,max);	
}
bool checkBST(struct Node *root){
	return checkBSTUtil(root,INT_MIN,INT_MAX);
}
int main(){
	struct Node *root = getNewNode(10);
	root->left = getNewNode(8);
	root->right = getNewNode(15);
	root->left->left = getNewNode(5);
	root->left->right = getNewNode(9);
	root->right->left = getNewNode(14);
	root->right->right = getNewNode(16);
	if(checkBST(root))
		cout<<"Yes\n";
	else cout<<"No\n";	
}
