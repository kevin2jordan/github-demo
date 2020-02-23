#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		string str;
		cin >> str;
		int freq[26];
		int res=0;
		vector<int> vec;
		for(int i=0;i<26;i++)
			freq[i] = 0;
		for(int i=0;i<str.length();i++)
			freq[str[i]-'A']++;	
		for(int i=0;i<26;i++){
			if(freq[i]!=0)
			vec.push_back(freq[i]);
		}
		sort(vec.begin(),vec.end());	
		for(int i=1;i<vec.size();i++){
			//	cout<<vec[i]<<" ";
			res+=vec[i]-vec[i-1];
		}
//		int minval = vec[0];
//		for(int i=1;i<vec.size();i++)
//			res+=vec[i]-minval;
		cout<<res<<endl;
	}
}
