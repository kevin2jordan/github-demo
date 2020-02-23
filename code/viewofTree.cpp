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
void leftView(struct Node *root){
	if(root == NULL)
		return ;
	queue<Node*> q;
	q.push(root);
	q.push(NULL);
	while(q.size() > 1){
		Node *temp = q.front();
		q.pop();
		if(temp == NULL){
			q.push(NULL);
			cout<<endl;
		}else{
			if(temp->left)
				q.push(temp->left);
			if(temp->right)
				q.push(temp->right);
			cout<<temp->data<<" ";		
		}
	}	
}
void leftViewRecursieUtil(struct Node *root, int level, int &max_level){
	if(root == NULL)
		return;
	if(max_level < level){
			max_level = level;
			cout<<root->data<<" ";
	}
	leftViewRecursieUtil(root->left,level+1,max_level);
	leftViewRecursieUtil(root->right,level+1,max_level);	
}
void rightViewRecursieUtil(struct Node *root, int level, int &max_level){
	if(root == NULL)
		return;
	if(max_level < level){
		cout<<root->data<<" ";
		max_level = level;
	}
	rightViewRecursieUtil(root->right,level+1,max_level);
	rightViewRecursieUtil(root->left,level+1,max_level);
			
}
void ViewRecursive(struct Node *root){
	int max_level = 0;
	cout<<"Left view of the given tree is ";
	leftViewRecursieUtil(root,1,max_level);
	cout<<endl<<endl;
	max_level = 0;
	cout<<"Right view of the given tree is ";
	rightViewRecursieUtil(root,1,max_level);
}
int main(){
	struct Node *root = getNewNode(1);
	root->left = getNewNode(2);
	root->right = getNewNode(3);
	root->left->left = getNewNode(4);
	root->left->right = getNewNode(5);
	root->right->left = getNewNode(6);
	root->right->right = getNewNode(7);
	root->right->left->left = getNewNode(8);
	root->right->left->right = getNewNode(9);
//	struct Node *root = getNewNode(12); 
//    root->left = getNewNode(10); 
//    root->right = getNewNode(30); 
//    root->right->left = getNewNode(25); 
//    root->right->right = getNewNode(40);
	ViewRecursive(root);
}
