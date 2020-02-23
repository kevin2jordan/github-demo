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
bool hasPath(struct Node *root, int dest, vector<int> &path){
	if(root == NULL)
		return false;
	path.push_back(root->data);
	if(root->data == dest)
		return true;
	if(hasPath(root->left,dest,path) ||
	   hasPath(root->right,dest,path))
	   		return true;
	path.pop_back();
	return false;		   		
} 
int main(){
	struct Node *root = getNewNode(1);
	root->left = getNewNode(2);
	root->right = getNewNode(3);
	root->left->left = getNewNode(4);
	root->left->right = getNewNode(5);
	root->right->left = getNewNode(6);
	root->right->right = getNewNode(7);
	int dest;
	cin >> dest;
	vector<int> path;
	if(hasPath(root,dest,path)){
		cout<<"Yes\n";
		for(int i=0;i<path.size();i++)
			cout<<path[i]<<" ";
	}else{
		cout<<"No\n";
	}
	
}
