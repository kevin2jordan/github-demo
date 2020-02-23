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
bool isIdentical(struct Node *root1,struct Node *root2){
	if(root1 == NULL && root2 == NULL)
		return true;
	if(root1 == NULL || root2 == NULL)
		return false;

	return (root1->data == root2->data) &&
		isIdentical(root1->left,root2->left) &&
		isIdentical(root1->right,root2->right);


}
int main(){
	struct Node *root1 = getNewNode(1);
	root1->left = getNewNode(2);
	root1->right = getNewNode(3);
	root1->left->left =getNewNode(4);
	root1->left->right = getNewNode(5);
	
	struct Node *root2 = getNewNode(1);
	root2->left = getNewNode(2);
	root2->right = getNewNode(3);
	root2->left->left = getNewNode(4);
	root2->left->right = getNewNode(5);
	
	if(isIdentical(root1,root2))
		cout<<"Yes\n";
	else cout<<"No\n";
}
