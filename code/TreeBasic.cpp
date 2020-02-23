#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node *left;
	Node *right;
};

/*creating newNode */

struct Node *getNewNode(int data){
	struct Node *temp = (Node*)malloc(sizeof(Node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

/*		Defth First Search 		*/

/*		Inorder traversal 		*/
void inOrder(struct Node *root){
	if(root == NULL)
		return;
	inOrder(root->left);
	cout<<root->data<<" ";
	inOrder(root->right);
	return;
}

/*			PreOrder traversal    */
void preOrder(struct Node *root){
	if(root == NULL)
		return;
	cout<<root->data<<" ";
	preOrder(root->left);
	preOrder(root->right);	
	return;
}

/* 		postOrder Traversal 		*/
void postOrder(struct Node *root){
	if(root == NULL)
		return;
	postOrder(root->left );
	postOrder(root->right);
	cout<<root->data<<" ";
	return;	
}

/* 		Breadth First Search 		*/
void levelOrder(struct Node *root){
	queue<Node*> q;
	q.push(root);
	while(!q.empty()){
		Node *temp = q.front();
		q.pop();
		cout<<temp->data<<" ";
		if(temp->left)
			q.push(temp->left);
		if(temp->right)
			q.push(temp->right);
				
	}
	return;
}

/* 		levelOrder Traversal In Spiral Order 		*/
void levelSpiralOrder(struct Node *root){
	if(root == NULL)
		return;
	stack<struct Node*> s1;
	stack<struct Node*> s2;
	s1.push(root);
	while(!s1.empty() || !s2.empty()){
		while(!s1.empty()){
			struct Node *temp =s1.top();
			s1.pop();
			cout<<temp->data<<" ";
			if(temp->right)
				s2.push(temp->right);
			if(temp->left)
				s2.push(temp->left);	
		}
		while(!s2.empty()){
			struct Node *temp = s2.top();
			s2.pop();
			cout<<temp->data<<" ";
			if(temp->left)
				s1.push(temp->left);
			if(temp->right)
				s1.push(temp->right);	
		}
	}
}

/*		levelOrder Traversal Line by Line  		*/
void levelOrderLineByLine(struct Node *root){
	cout<<"Inside \n";
	if(root == NULL)
		return;
	queue<Node*> q;
	q.push(root);
	q.push(NULL);
	while(q.size() > 1){
		Node *temp = q.front();
		q.pop();
		if(temp == NULL){
			cout<<endl;
			q.push(NULL);
		}
		else {
			cout<<temp->data<<" ";
		if(temp->left)
			q.push(temp->left );
		if(temp->right)
			q.push(temp->right);
		}
			
	}	
}

/* reverser Level Order Traversal */
void reverseLevelOrder(struct Node *root){
	if(root == NULL){
		return;
	}
	queue<Node*> q;
	q.push(root);
	stack<int> st;
	while(!q.empty()){
		Node *temp = q.front();
		q.pop();
		st.push(temp->data);
		if(temp->right)
			q.push(temp->right);
		if(temp->left)
			q.push(temp->left);	
	}
	while(!st.empty()){
		cout<<st.top()<<" ";
		st.pop();
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
//	cout<<"inOrder Traversal ";
//	inOrder(root);
//	cout<<endl;
//	cout<<"preOrder Traversal ";
//	preOrder(root);
//	cout<<endl;
//	cout<<"postOrder Traversal ";
//	postOrder(root);
//	cout<<endl;
//	cout<<"levelOrder Traversal ";
//	levelOrder(root);
//	cout<<endl;
//	cout<<"spiral LevelOrder traversal ";
//	levelSpiralOrder(root);
//	cout<<endl;
	cout<<"Level Order traversal Line By Line ";
	levelOrderLineByLine(root);
	cout<<endl;
	cout<<"Reverse Level order Traversal ";
	reverseLevelOrder(root);
}
