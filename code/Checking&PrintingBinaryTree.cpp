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
int sum(struct Node *root){
	if(root == NULL)
		return 0;
	return sum(root->left) + root->data + sum(root->right);
}


bool isSumTree(struct Node *root){
	if(root == NULL || (root->left ==NULL && root->right == NULL))
		return true;
	else {
		int leftSum = sum(root->left);
		int rightSum = sum(root->right);
		if((root->data == leftSum + rightSum)&&
		isSumTree(root->left) && isSumTree(root->right))
			return true;
		else return false;	
	}	
}
bool childreSumProperty(struct Node *root){
  int left_data = 0,  right_data = 0; 
  if(root == NULL || 
     (root->left == NULL && root->right == NULL)) 
    return true; 
  else
  { 
    if(root->left != NULL) 
      left_data = root->left->data; 
  
    if(root->right != NULL) 
      right_data = root->right->data; 
  
    if((root->data == left_data + right_data)&& 
        childreSumProperty(root->left) && 
        childreSumProperty(root->right)) 
      return true; 
    else
      return false; 
  } 
}
bool isBSTUtil(struct Node *root, int min, int max){
	/* checking if tree is empty or it has only one Node */
	
	if(root == NULL || (root->left == NULL && root->right == NULL))
		return true;
	if(root->data < min  || root->data > max)
		return false;
	return isBSTUtil(root->left,min,root->data-1) &&
		   isBSTUtil(root->right,root->data+1,max);				
}
bool isBST(struct Node *root){
	return isBSTUtil(root,INT_MIN,INT_MAX);
}
int main(){
  struct Node *root  = getNewNode(4); 
  root->left         = getNewNode(2); 
  root->right        = getNewNode(5); 
  root->left->left   = getNewNode(1); 
  root->left->right  = getNewNode(3); 
  root->right->right = getNewNode(6); 
//	if(childreSumProperty(root)){
//		cout<<"Yes\n";
//	}else cout<<"No\n";
//	
//	if(isSumTree(root)){
//		cout<<"Yes\n";
//	}else{
//		cout<<"No\n";
//	}	
if(isBST(root))
	cout<<"Yes\n";
else cout<<"No\n";		
	
}
