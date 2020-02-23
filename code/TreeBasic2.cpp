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
int height(struct Node *root){
	if(root == NULL)
		return 0;
	return max(height(root->left),height(root->right))+1;	
}
int size(struct Node *root){
	if(root == NULL)
		return 0;
	return size(root->left)+size(root->right)+1;	
}
int diameter(struct Node *root, int &ans){
	if(root == NULL)
		return 0;
	int left_ht = diameter(root->left,ans);
	int right_ht = diameter(root->right,ans);
	ans = max(ans, 1+left_ht+right_ht);
	cout<<"Ans ki val "<<ans<<endl;
	return 1 + max(left_ht,right_ht);	
}
int main(){
	int ans=INT_MIN;
	struct Node *root = getNewNode(1);
	root->left = getNewNode(2);
	root->right = getNewNode(3);
	root->left->left = getNewNode(4);
	root->left->right = getNewNode(5);
	root->right->left = getNewNode(6);
	root->right->right = getNewNode(7);
//	cout<<"Height of the Tree is  "<<height(root)<<endl;
//	cout<<"Size of the Tree is  "<<size(root)<<endl;
	diameter(root,ans);
	cout<<"Diameter of the Tree is  "<<ans<<endl;
}
