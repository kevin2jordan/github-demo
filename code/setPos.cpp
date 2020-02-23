#include<bits/stdc++.h>
using namespace std;
int setPos(int n){
	int cnt=1;
	queue<int> q;
	while(n){
		int temp = n%2;	
		q.push(temp);
		n = n/2;
	}
	while(!q.empty()){
		int u = q.front();
		if(u==1)
			return cnt;
		 cnt++;
		q.pop();	
	}
}
int setPosSol(int n){
	return log2(n & -n) + 1;
}
int main(){
	int t;
	cin >> t;
	while(t--){
	int n;
	cin >> n;
	cout<<setPosSol(n)<<endl;
}
return 0;
}
