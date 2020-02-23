#include<bits/stdc++.h>
using namespace std;
#define llt long long int
#define endl "\n"
int main(){
	ios_base;;sync_with_stdio;
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		llt a,b,n,k;
		cin >> n >> a >> b >> k;
		llt res=0;
		for(int i=1;i<=n;i++){
			if(i%a==0 && i%b!=0){
					res++;
			}
			if(i%b==0 && i%a!=0){
					res++;
			}
		}
	res>=k ? cout<<"Win\n" : cout<<"Lose\n";
	}
}
