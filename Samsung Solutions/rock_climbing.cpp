#include<iostream>
using namespace std;
int a[50][50];
int visit[50][50];

struct pair1{
	int ax;
	int ay;
};
pair1 queue1[2500];
int start1,end1;

int calculate_bfs(int x,int y,int n,int m,int k){
	visit[x][y]=1;
	start1=end1=0;
	pair1 p;
	p.ax=x;
	p.ay=y;
	queue1[end1++]=p;
	while(start1!=end1){
		int x=queue1[start1].ax;
		int y=queue1[start1].ay;
		start1++;
		int flag1=true,flag2=true;
		for(int i=1;i<=k;i++){
			if(x-i>=0 && visit[x-i][y]==0 && (a[x-i][y]==1 || a[x-i][y]==3)){
				p.ax=x-i;
				p.ay=y;
				visit[x-i][y]=1;
				queue1[end1++]=p;
				if(a[x-i][y]==3)return k;
			}
			if(x+i<=n && visit[x+i][y]==0 && (a[x+i][y]==1 || a[x+i][y]==3)){
				p.ax=x+i;
				p.ay=y;
				visit[x+i][y]=1;
				queue1[end1++]=p;
				if(a[x+i][y]==3)return k;
			}
			if(y-i>=0 && visit[x][y-i]==0){
				if(flag1 && (a[x][y-i]==1 || a[x][y-i]==3)){
					p.ax=x;
					p.ay=y-i;
					visit[x][y-i]=1;
					queue1[end1++]=p;
					if(a[x][y-i]==3)return k;
				}
				else if(a[x][y+i]==0)flag1=false;
			}
			if(y+i<m && visit[x][y+i]==0){
				if(flag2 && (a[x][y+i]==1 || a[x][y+i]==3)){
					p.ax=x;
					p.ay=y+i;
					visit[x][y+i]=1;
					queue1[end1++]=p;
					if(a[x][y+i]==3)return k;
				}
				else if(a[x][y+i]==0)flag2=false;
			}
		}
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int test;
	cin>>test;
	for(int t=1;t<=test;t++){
		int n,m;
		cin>>n>>m;
		int t1;
		for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin>>a[i][j];
		for(int k=1;k<n;k++){
			for(int i=0;i<n;i++)for(int j=0;j<m;j++)visit[i][j]=0;
			t1=calculate_bfs(n-1,0,n,m,k);
			if(t1!=0)break;
		}
		cout<<"#"<<t<<" "<<t1<<endl;
	}
	return 0;
}