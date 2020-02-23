#include<bits/stdc++.h>
using namespace std;
#define llt long long int
llt maxVal(llt x, llt y){
	if(x>y)
		return x;
	else return y;	
}
int main(){
	int t;
	cin >> t;
	while(t--){
		llt n,k;
		llt arr[n];
		cin >> n;
		llt res = INT_MIN;
		for(int i=0;i<n;i++){
			cin >> arr[i];
			res = maxVal(res,arr[i]);
		}
		llt diff=0;
		for(int i=1;i<n;i++)
		diff+=abs(arr[i]-arr[i-1]);
		cout<<res+diff<<endl;
	}
	
}
