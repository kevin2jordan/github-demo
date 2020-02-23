#include <bits/stdc++.h> 
using namespace std; 
#define MAX_CHAR  26
#define llt long long int
llt commonCharacters(vector<string> str, int n) 
{ 
	bool first[MAX_CHAR]; 
	llt ans=0;
	memset(first, true, sizeof(first)); 

	for (int i = 0; i < n; i++) { 

		bool sec[MAX_CHAR] = { false }; 

		for (int j = 0; str[i][j]; j++) { 

			if (first[str[i][j] - 'a']) 
				sec[str[i][j] - 'a'] = true; 
		} 

		memcpy(first, sec, MAX_CHAR); 
	} 

	for (int i = 0; i < 26; i++) 
		if (first[i]) 
			ans++;
return ans;			
} 

int main() 
{ 
	int t;
	cin >> t;
	while(t--){
	int n;
	cin >> n;
	vector<string> str; 
	for(int i=0;i<n;i++){
		string temp;
		cin >> temp;
		str.push_back(temp);
	}
	
	cout<<commonCharacters(str,n)<<endl; 
}
	return 0; 
} 


