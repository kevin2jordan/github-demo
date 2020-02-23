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
void verticalOrderUtil(struct Node *root, int hd, map<int,vector<int> > &mp){
	if(root == NULL)	
		return;
	mp[hd].push_back(root->data);
	verticalOrderUtil(root->left,hd-1,mp);
	verticalOrderUtil(root->right,hd+1,mp);	
}
void verticalOrder(struct Node *root){
	int hd=0;
	map<int,vector<int> > mp;
	verticalOrderUtil(root,hd,mp);
	map<int,vector<int> >::iterator it;
	for(it=mp.begin();it!=mp.end();it++){
		for(int i=0 ; i<it->second.size();i++)
			cout<<it->second[i]<<" ";
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
	verticalOrder(root);
}
