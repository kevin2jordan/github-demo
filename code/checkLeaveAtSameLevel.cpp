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
bool checkLeaveAtSameLevel(struct Node *root, int level, int &max_level){
	if(root == NULL)
		return true;
	if(root->left == NULL && root->right == NULL){
		if(max_level == 0){
			max_level = level;
			return true;
		}
		return (level == max_level);
	}	
	return checkLeaveAtSameLevel(root->left,level+1,max_level) &&
		   checkLeaveAtSameLevel(root->right,level+1,max_level);
}
int main(){
	struct Node *root = getNewNode(1);
	root->left = getNewNode(2);
	root->right = getNewNode(3);
	root->left->left = getNewNode(4);
	root->left->right = getNewNode(5);
	root->right->left = getNewNode(6);
	root->right->right = getNewNode(7);
	int max_level = 0;
	int level = 0;
	if(checkLeaveAtSameLevel(root,level,max_level)){
		cout<<"Yes\n";
	}else{
		cout<<"No\n";
	}
}
