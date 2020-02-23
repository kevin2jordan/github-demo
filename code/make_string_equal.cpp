#include<bits/stdc++.h>
using namespace std;
int main(){
	string str;
	cin >> str;
	int freq[26];
	for(int i=0;i<26;i++)
		freq[i]=0;
		
	for(int i=0;i<str.length();i++)
		freq[str[i]-'a']++;
	
	for(int i=0;i<26;i++){
		cout<<i<<" "<<freq[i]<<endl;
	}	
	
}
