#include<iostream>
using namespace std;
struct Node{
	int data;
	Node *next;
};
Node *head[10000];
int a[10000];
int start1,end1;

Node *get_new_node(int val){
	Node *new_node=new Node();
	new_node->data=val;
	new_node->next=NULL;
	return new_node;
}

Node *insert(int x,int val){
	if(head[x]==NULL)head[x]=get_new_node(val);
	else{
		Node *ptr=get_new_node(val);
		ptr->next=head[x];
		head[x]=ptr;
	}
	return head[x];
}

void calculate_time_at_each_node(int time[],int vertex){
	start1=0;
	end1=0;
	a[end1++]=1;
	time[1]=10;
	while(start1!=end1){
		int t=a[start1++];
		Node *ptr=head[t];
		while(ptr!=NULL){
			if(!time[ptr->data]){
				time[ptr->data]=10+time[t];
				a[end1++]=ptr->data;
			}
			ptr=ptr->next;
		}
	}
}

int main(){
	int test;
	cin>>test;
	while(test--){
		int vertex;  //total vertexes
		cout<<"Enter Total Vertex : ";
		cin>>vertex;
		int edges;	// total edges
		cout<<"Enter Total Edges : ";
		cin>>edges;
		for(int i=1;i<=vertex;i++)head[i]=NULL;
		int x,y;
		int c=edges;
		while(c--){
			cin>>x>>y;
			head[x]=insert(x,y);
			head[y]=insert(y,x);
		}
		int time1;
		cin>>time1;
		if(time1==0)time1++;
		if(time1%10!=0)time1=((time1/10)+1)*10;
		cout<<"time1="<<time1<<endl;
		int time[vertex+1];
		for(int i=1;i<=vertex;i++)time[i]=0;
		calculate_time_at_each_node(time,vertex);
		int count=0;
		for(int i=1;i<=vertex;i++){
			if(time[i]==time1){
				count++;
				cout<<i<<" ";
			}
		}
		if(count==0)cout<<"NOT FOUND"<<endl<<"prob : 0"<<endl;
		else{
			double a= double(100/(double)count);
			cout<<endl<<"prob : 1/"<<count<<" or "<<a<<"%"<<endl;
		}
	}
	return 0;
}