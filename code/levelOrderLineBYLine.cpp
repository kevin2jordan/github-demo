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
void levelOrderLineByLine(struct Node *root){
	cout<<"Inside\n";
	if(root == NULL)
		return;;
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
int main(){
	struct Node *root = getNewNode(1);
	root->left = getNewNode(2);
	root->right = getNewNode(3);
	root->left->left = getNewNode(4);
	root->left->right = getNewNode(5);
	root->right->left = getNewNode(6);
	root->right->right = getNewNode(7);
	levelOrderLineByLine(root);
}
