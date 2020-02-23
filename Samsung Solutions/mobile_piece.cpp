#include<iostream>
using namespace std;
int matrix[1000][1000];
int visit[1000][1000];
int x_move[]={-2,-2,-1,1,2,2,1,-1};
int y_move[]={-1,1,2,2,1,1,-2,-2};

struct queue1{
	int x;
	int y;
	int count;
};

queue1 q[100000];
queue1 pair1;
int start1,end1;

bool check(int nx,int ny,int n,int m){
	if(nx<1 || nx>n || ny<1 || ny>m || visit[nx][ny]==1 || (matrix[nx][ny]!=0 && matrix[nx][ny]!=1) )return false;
	return true;
}

void calculate_bfs(int dx,int dy,int n,int m,int &min_distance){
	while(start1!=end1){
		int ax=q[start1].x;
		int ay=q[start1].y;
		int co=q[start1].count;
		start1++;
		visit[ax][ay]=-1;
		for(int i=0;i<8;i++){
			int new_x=ax+x_move[i];
			int new_y=ay+y_move[i];
			if(check(new_x,new_y,n,m)){
				visit[new_x][new_y]=1;
				pair1.x=new_x;
				pair1.y=new_y;
				pair1.count=co+1;
				q[end1++]=pair1;
			}
			if(new_x=dx && new_y==dy){
				min_distance=co+1;
				return;
			}
		}
	}
}

int main(){
	int test;
	cin>>test;
	while(test--){
		int n,m;
		cin>>n>>m;
		int s_x,s_y,d_x,d_y;
		cin>>s_x>>s_y>>d_x>>d_y;
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>matrix[i][j];
		int min_distance=-1;
		start1=0;
		end1=0;
		pair1.x=s_x;
		pair1.y=s_y;
		pair1.count=0;
		q[end1++]=pair1;
		calculate_bfs(d_x,d_y,n,m,min_distance);
		cout<<min_distance<<endl;
	}
	return 0;
}