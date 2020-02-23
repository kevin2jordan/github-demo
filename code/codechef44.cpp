#include<bits/stdc++.h>
using namespace std;
#define n 1000007
#define llt long long int
bool prime[n];
void primeVal(){
	for(int i=0;i<n;i++)
		prime[i]=true;
	prime[0]=false;
	prime[1]=false;
	for(int i=2;i<=sqrt(n);i++){
		if(prime[i]){
			for(int j=i*i;j<=n;j+=i)
				prime[j] = false;
		}
	}	
}
int main(){
		primeVal();
		int t;
		cin >> t;
		while(t--){
			string str;
			cin >> str;
			llt freq[26];
			llt maxVal = INT_MIN;
			llt totalSum=0;
			for(int i=0;i<26;i++)
				freq[i]=0;
			for(int i=0;i<str.length();i++)
				freq[str[i]-'A']++;
			for(int i=0;i<26;i++){
					maxVal = max(maxVal,freq[i]);
					totalSum +=freq[i];
			}
			if(prime[totalSum]){
				cout<<totalSum-maxVal<<endl;
			}
						
		}
		
}
