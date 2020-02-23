#include<bits/stdc++.h>
using namespace std;
struct Node {
	int data;
	int hd;
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
void topViewIterative(struct Node *root){
	if(root == NULL)
		return;
	queue<Node*> q;
	q.push(root);
	int hd=0;
	root->hd = hd;
	map<int,int> mp;
	while(!q.empty()){
		Node *temp = q.front();
	//	cout<<temp->data<<" ";
		q.pop();
		hd = temp->hd;
		if(mp.count(hd) == 0){
			mp[hd] = temp->data;
		}
		if(temp->left){
			q.push(temp->left);
			temp->left->hd = hd+1;
		}
		if(temp->right){
			q.push(temp->right);
			temp->right->hd = hd-1;
		}
	}
	map<int,int>::iterator it;
	for(it = mp.begin();it!=mp.end();it++){
		cout<<it->second<<" ";
	}		
}
void bottomViewIterative(struct Node *root){
	if(root == NULL)
		return;
	queue<Node*> q;
	int hd = 0;
	q.push(root);
	root->hd = hd;
	map<int,int> mp;	
	while(!q.empty()){
		Node *temp = q.front();
		q.pop();
		hd = temp->hd;
		mp[hd] = temp->data;
		if(temp->left){
			q.push(temp->left);
			temp->left->hd = hd-1;
		}
		if(temp->right){
			q.push(temp->right);
			temp->right->hd = hd+1;
		}
	}
	map<int,int> ::iterator it;
	for(it =mp.begin();it!=mp.end();it++)
		cout<<it->second<<" ";
}
int main(){

	Node *root = getNewNode(20); 
    root->left = getNewNode(8); 
    root->right = getNewNode(22); 
    root->left->left = getNewNode(5); 
    root->left->right = getNewNode(3); 
    root->right->left = getNewNode(4); 
    root->right->right = getNewNode(25); 
    root->left->right->left = getNewNode(10); 
    root->left->right->right = getNewNode(14); 
    
//	Node* root = getNewNode(1); 
//    root->left = getNewNode(2); 
//    root->right = getNewNode(3); 
//    root->left->right = getNewNode(4); 
//    root->left->right->right = getNewNode(5); 
//    root->left->right->right->right = getNewNode(6); 
	bottomViewIterative(root);
}
