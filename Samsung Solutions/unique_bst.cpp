#include<iostream>
using namespace std;
#define ll long long int
int dp[1000];

int main(){
	dp[0]=1;
	dp[1]=1;
	for(int i=2;i<=1000;i++){
		int l=0;
		int r=i-1;
		ll sum=0;
		while(l<r){
			sum+=(2*dp[l]*dp[r]);
			l++;
			r--;
		}
		if(l==r)sum+=(dp[l]*dp[r]);
		dp[i]=sum;
	}
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		cout<<dp[n]<<endl;
	}
	return 0;
}