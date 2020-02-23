#include<bits/stdc++.h>
using namespace std;
vector<int> *adj;
bool *visited;
void topologicalSort(int src, stack<int> &st){
	visited[src]=true;
	for(int i=0;i<adj[src].size();i++){
		if(!visited[adj[src][i]])
			topologicalSort(adj[src][i],st);
	}
	st.push(src);
}
int main(){
	int nodes,edges;
	cin >> nodes >> edges;
	adj = new vector<int>[nodes+1];
	visited = new bool[nodes+1];
	for(int i=0;i<=nodes;i++)
		visited[i] = false;
	for(int i=0;i<edges;i++){
		int x,y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}	
	stack<int> st;
	for(int i=0;i<nodes;i++){
		if(!visited[i])
			topologicalSort(i,st);
	}
		while(!st.empty()){
		cout<<st.top()<<" ";
		st.pop();
	}
}
