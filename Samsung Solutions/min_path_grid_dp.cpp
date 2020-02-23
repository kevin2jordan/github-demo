#include<iostream>
using namespace std;
int a[100][100];
int dp[100][100];


void fill_dp_table(int n,int m){
	dp[0][0]=0;
	for(int i=1;i<m;i++){							// fill 1st row
		if(a[0][i]!=0)dp[0][i]=1+dp[0][i-1];
		else dp[0][i]=10000;
	}
	for(int i=1;i<n;i++){							//fill 1st column
		if(a[i][0]!=0)dp[i][0]=1+dp[i-1][0];
		else dp[i][0]=10000;
	}
	for(int i=1;i<n;i++){							//fill rest boxes
		for(int j=1;j<m;j++){
			if(a[i][j]!=0)dp[i][j]=1+min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]);
			else dp[i][j]=10000;
		}
	}
}

int main(){
	int test;
	cin>>test;
	while(test--){
		int n,m;
		cin>>n>>m;
		for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin>>a[i][j];
		fill_dp_table(n,m);
		cout<<dp[n-1][m-1]<<endl;
	}
	return 0;
}