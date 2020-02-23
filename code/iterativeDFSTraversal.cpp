/* converting caffiene into Code */

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

void inorder(struct Node *root){
	if(root == NULL)
		return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);	
}

void inorderIterative(struct Node *root){
	if(root == NULL)
		return;
	stack<Node *> st;
	struct Node *curr = root;
	while(curr != NULL || !st.empty()){
		while(curr != NULL){
			st.push(curr);
			curr = curr->left;
		}
		curr = st.top();
		st.pop();
		cout<<curr->data<<" ";	
		curr = curr->right;	
	}	
}
void preorder(struct Node *root){
	if(root == NULL)
		return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);	
}

void preorderIterative(struct Node *root){
	if(root == NULL){
		return;
	}
	stack<Node*> st;
	st.push(root);
	while(!st.empty()){
		Node *temp = st.top();
		st.pop();
		cout<<temp->data<<" ";
		if(temp->right != NULL)
			st.push(temp->right);
		if(temp->left != NULL)
			st.push(temp->left);	
	}
	
}

void postorder(struct Node *root){
	if(root == NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";	
}

void postorderIterative(struct Node *root){
	if(root == NULL){
		return;
	}
	stack<Node *> s1,s2;
	s1.push(root);
	while(!s1.empty()){
		Node *temp = s1.top();
		s1.pop();
		s2.push(temp);
		if(temp->left)
			s1.push(temp->left);
		if(temp->right)
			s1.push(temp->right);	
	}
	while(!s2.empty()){
		cout<<s2.top()->data<<" ";
		s2.pop();
	}
}
int main(){
	struct Node *root = getNewNode(1);
	root->left = getNewNode(2);
	root->right = getNewNode(3);
	root->left->left = getNewNode(4);
	root->left->right = getNewNode(5);
	root->right->left = getNewNode(6);
	root->right->right = getNewNode(7);
	cout<<"Inorder Traversal recursive ";
	inorder(root);
	cout<<endl<<endl;
	cout<<"Inorder Traversal iterative ";
	inorderIterative(root);
	cout<<endl<<endl;
	cout<<"preorder Traversal recursive ";
	preorder(root);
	cout<<endl<<endl;
	cout<<"preorder Traversal iterative ";
	preorderIterative(root);
	cout<<endl<<endl;
	cout<<"postorder Traversal recursive ";
	postorder(root);
	cout<<endl<<endl;
	cout<<"postorder Traversal iterative ";
	postorderIterative(root);
}

