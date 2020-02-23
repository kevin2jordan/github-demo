#include<bits/stdc++.h>
using namespace std;
bool check(string str1, string str2){
	string temp1 = str2.substr(str2.length()-2)+str2.substr(0,str2.length()-2);
	string temp2 = str2.substr(2)+str2.substr(0,2);
	return str1==temp1 || str1 == temp2;
	
}
int main(){
	int t;
	cin >> t;
	while(t--){
	
	string str1,str2;
	cin >> str1 >> str2;
	if(check(str1,str2))
		cout<<"Yes\n";
	else cout<<"No\n";	
}
return 0;
}
