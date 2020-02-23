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
bool isIdentical(struct Node *root1, struct Node *root2){
	if(root1 == NULL && root2 == NULL)
		return true;
	if(root1 == NULL || root2 == NULL)
		return false;
	return (root1->data == root2->data &&
		   isIdentical(root1->left,root2->left) &&
		   isIdentical(root1->right,root2->right));		
}
bool isSubTree(struct Node *tree, struct Node *subTree){
	if(subTree == NULL)
		return true;
	if(tree == NULL)
		return false;
	if(isIdentical(tree, subTree))
		return true;	
	return isSubTree(tree->left,subTree) &&
		   isSubTree(tree->right,subTree);		
}
int main(){
//	struct Node *root = getNewNode(1);
//	root->left = getNewNode(2);
//	root->right = getNewNode(3);
//	root->left->left = getNewNode(4);
//	root->left->right = getNewNode(5);
//	root->right->left = getNewNode(6);
//	root->right->right = getNewNode(7);
//	
//	struct Node *subroot = getNewNode(1);
//	subroot->left = getNewNode(2);
//	subroot->right = getNewNode(3);
//	subroot->left->left = getNewNode(4);
//	subroot->left->right = getNewNode(5);
	 struct Node *T        = getNewNode(26); 
    T->right              = getNewNode(3); 
    T->right->right       = getNewNode(3); 
    T->left               = getNewNode(10); 
    T->left->left         = getNewNode(4); 
    T->left->left->right  = getNewNode(30); 
    T->left->right        = getNewNode(6); 
  
    // TREE 2 
    /* Construct the following tree 
          10 
        /    \ 
      4      6 
       \ 
        30 
    */
    struct Node *S    = getNewNode(10); 
    S->right          = getNewNode(6); 
    S->left           = getNewNode(4); 
    S->left->right    = getNewNode(30);
	if(isSubTree(T,S))
		cout<<"Yes\n";
	else cout<<"No\n";	
}
