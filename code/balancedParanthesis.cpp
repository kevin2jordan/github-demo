#include<bits/stdc++.h>
using namespace std;
bool isBalanced(string str){
	stack<char> st;
	char x;
	for(int i=0;i<str.length();i++){
		if(str[i] == '(' || str[i] == '{' || str[i] == '['){
			st.push(str[i]);
			continue;
		}
		// handling the case }}}{}[]
		if(st.empty()){
			return false;
		}
		switch(str[i]){
			case ')':
				 x = st.top();
				st.pop();
				if(x == '{' || x == '[')
					return false;
				break;
			case '}':
				x = st.top();
				st.pop();
				if(x =='(' || x =='[')
					return false;
				break;
			case ']':
				 x = st.top();
				st.pop();
				if(x == '(' || x == '{')
					return false;
				break;					
		}
	}
	return st.empty();
}
int main(){
	string str;
	cin >> str;
	if(isBalanced(str)){
		cout<<"Yes\n";
	}else{
		cout<<"No\n";
	}
}
