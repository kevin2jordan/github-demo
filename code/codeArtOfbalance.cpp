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
		string str;
		cin >> str;
		int freq[26];
		llt res=0;
		vector<llt> vec;
		for(int i=0;i<26;i++)
			freq[i] = 0;
		for(int i=0;i<str.length();i++)
			freq[str[i]-'A']++;	
		for(int i=0;i<26;i++){
			if(freq[i]!=0)
			vec.push_back(freq[i]);
		}
		llt gcd=0;
		llt tempval=0;
		for(int i=1;i<vec.size();i++){
			tempval+=vec[i];
			gcd = __gcd(vec[i],vec[i-1]);
		}
	//	cout<<"gcd ki val "<<gcd<<endl;
		if(vec.size()==1)
			cout<<0<<endl;
		else{
			
		for(int i=0;i<vec.size();i++)
			res+=vec[i]-gcd;
			if(tempval&1)
		cout<<res<<endl;
		else cout<<res/2<<endl;
	}
	}
}
