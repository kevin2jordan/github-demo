#include<iostream>
using namespace std;
struct node{
	int data;
	node* next;
};
node* getNewNode(int val){
	node* y=(node*) new node;
	y->data=val;
	y->next=NULL;
	return y;
}

node* insertAtFront(node* head,int val){
	if(head==NULL) return getNewNode(val);
	node* t=getNewNode(val);
	t->next=head;
	return t;
}

void printList(node* head){
	while(head){
		cout<<head->data<<" ";
		head=head->next;
	}
}

void printGraph(node* head[],int n){
	for(int i=1;i<n+1;i++){
		cout<<i<<"-> ";
		printList(head[i]);
		cout<<endl;
	}
}

struct matrix{
	node* val;
	matrix* down;
};
int visited[100];
int parentArray[100];
matrix* realHead = NULL; 

matrix* getNewMatrixNode(node* val){
	matrix* temp= (matrix*)new matrix;
	temp->val=val;
	temp->down=NULL;
	return temp;
}
void countCycle(int start, int end){
	node* head;
	if(start!=end){
		head= getNewNode(end);
		node* temp=head;
		//cout<<end<<endl;
		temp->next=getNewNode(start);
		temp=temp->next;
		//cout<<start<<endl;
		while(parentArray[start]!=end){
			//cout<<parentArray[start]<<endl;
			temp->next=getNewNode(parentArray[start]);
			start=parentArray[start];
			temp=temp->next;
		}
		//cout<<end<<endl;
		temp->next=getNewNode(end);
		temp=temp->next;
	}
	else{
		head= getNewNode(end);
		node* temp=head;
		//cout<<end<<endl;
		temp->next=getNewNode(start);
		temp=temp->next;
	}
	matrix* temp1=realHead;
	if(temp1==NULL) {
		temp1=getNewMatrixNode(head);
		realHead=temp1;
	}
	else{
		while(temp1->down!=NULL){
			temp1=temp1->down;
		}
		temp1->down=getNewMatrixNode(head);
	} 
}
int nextOne(int n){
	for(int i=1;i<n+1;i++){
		if(visited[i]==0) return i;
	}
	return -1;
}
bool dfs(node* graph[],int n,int start){
	visited[start]=1;
	for(node* temp=graph[start];temp!=NULL;temp=temp->next){
		if(parentArray[start]==temp->data) continue;
		if(visited[temp->data]==1) {
			countCycle(start,temp->data);
			return true;
		}
		parentArray[temp->data]=start;
		if(dfs(graph,n,temp->data)) return true;
	}
	return false;
}
bool findCycle(node* graph[],int n){
	int t=nextOne(n);
	bool flag=false;
	while(t!=-1){
		parentArray[t]=-1;
		if(dfs(graph,n,t)) flag=true;
		t=nextOne(n); 
	}
	return flag;
}
int main(){
	int n,e;
	cin>>n>>e;
	node* graph[n+1];
	for(int i=0;i<n+1;i++) graph[i]=NULL;
	for(int i=0;i<e;i++){
		int x,y;
		cin>>x>>y;
		graph[x]=insertAtFront(graph[x],y);
		graph[y]=insertAtFront(graph[y],x);
	}
	printGraph(graph,n);
	cout<<"Graph has cycle? ";
	cout<<(findCycle(graph,n)?"Yes":"No")<<endl;
	for(int i=1;i<n+1;i++){
		cout<<i<<" "<<parentArray[i]<<endl;
	}
	// cout<<endl;
	int cnt=0;
	for(matrix* t=realHead;t!=NULL;t=t->down){
		cnt++;
		printList(t->val);
		cout<<endl;
	}
	cout<<"Total No. of Cycle:"<<cnt<<endl;
	return 0;
}