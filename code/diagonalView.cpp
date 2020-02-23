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
void diagonalView(struct Node *root, int d, map<int,vector<int> > &diagonal){
	if(root == NULL)
		return;
	diagonal[d].push_back(root->data);	
	diagonalView(root->left,d+1,diagonal);	
	diagonalView(root->right,d,diagonal);
}
int main(){
	struct Node *root = getNewNode(1);
	root->left = getNewNode(2);
	root->right = getNewNode(3);
	root->left->left = getNewNode(4);
	root->left->right = getNewNode(5);
	root->right->left = getNewNode(6);
	root->right->right = getNewNode(7);
	
	map<int,vector<int> > diagonal;
	diagonalView(root,0,diagonal);
	
	map<int,vector<int> >::iterator it;
	vector<int> :: iterator i;
	for(it=diagonal.begin();it!=diagonal.end();it++){
		for( i=it->second.begin(); i!=it->second.end(); i++)
			cout<<*i<<" ";
	}
}
