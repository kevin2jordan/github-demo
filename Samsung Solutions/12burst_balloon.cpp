#include<iostream>
using namespace std;
int dp[1001][1001];

void calculate(int a[],int n){
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)dp[i][j]=0;
	for(int len=1;len<=n;len++){
		for(int i=0;i<=n-len;i++){
			int j=i+len-1;
			for(int k=i;k<=j;k++){
				int left_value=-1;
				int right_value=-1;
				if(i!=0)left_value=a[i-1];
				if(j!=n-1)right_value=a[j+1];
				int before=0;
				int after=0;
				if(i!=k)before=dp[i][k-1];
				if(j!=k)after=dp[k+1][j];
				int c;
                if(left_value==-1 && right_value==-1)c=a[k];
                else if(left_value==-1)c=right_value;
                else if(right_value==-1)c=left_value;
                else c=left_value*right_value;
                int t=(c+before+after);
				if(dp[i][j]<t)dp[i][j]=t;
			}
		}
	}
}

int main(){
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)cin>>a[i];
		calculate(a,n);
		cout<<dp[0][n-1]<<endl;
	}
	return 0;
}