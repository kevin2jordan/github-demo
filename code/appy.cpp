#include<bits/stdc++.h>
using namespace std;
#define llt long long int
#define endl "\n"
int main(){
	ios_base::sync_with_stdio;
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		llt n,a,b,k;
		cin >> n >> a >> b >>k;
		llt temp1=0,temp2=0,temp3=0;
		temp1 = n/a;
		temp2 = n/b;
		llt gcd = __gcd(a,b);
		llt lcm = (a*b)/gcd;
		temp3 = n/lcm;
		llt res = temp1+temp2 - 2*temp3;
	//	cout<<res<<endl;
		res>=k ? cout<<"Win\n" : cout<<"Lose\n";
	}
}
