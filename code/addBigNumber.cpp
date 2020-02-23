#include<bits/stdc++.h>
using namespace std;
int main(){
	string x,y ;
	cin >> x >> y;
	reverse(x.begin(),x.end());
	reverse(y.begin(),y.end());
	cout<<x<<" "<<y<<endl;
	int carry = 0;
	int sum=0;
	string resSum="";
	int n1 = x.length();
	int n2 = y.length();
	for(int i=0;i<n1;i++){
		sum=(x[i]-'0' + y[i]-'0') + carry;
		resSum+=(sum%10+'0');
		carry = sum/10;
	}
	for(int i=n1;i<n2;i++){
		sum = (y[i]-'0') + carry;
		resSum += sum%10 + '0';
		carry = sum/10;
	}
	if(carry)
		resSum += carry + '0';
	reverse(resSum.begin(),resSum.end());
	cout<<resSum<<endl;
}
