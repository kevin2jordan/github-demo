#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define llt long long int
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		llt k,sum=0;
		cin >> n;
		for(int i=0;i<n;i++){
			cin>>k;
			sum+=k;
		}
		cout<<sum-(n-1)<<endl;
	}
}
