#include<bits/stdc++.h>
using namespace std;
#define n 100
bool primeNum[n];
void prime(){
	for(int i=0;i<n;i++)
		primeNum[i] = true;
	for(int i=2;i<=sqrt(n);i++){
		if(primeNum[i])
		for(int j=i*i;j<=n;j+=i)
			primeNum[j] = false;
	}	
}
int main(){
	prime();
	for(int i=2;i<n;i++)
		if(primeNum[i])
			cout<<i<<" ";
}

