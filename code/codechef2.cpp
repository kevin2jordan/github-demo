#include<bits/stdc++.h>
using namespace std;
#define llt long long int
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		llt att[n];
		for(int i=0;i<n;i++)
			cin >> att[i];
		llt def[n];
		for(int i=0;i<n;i++)
			cin >> def[i];
		bool temp[n];
		for(int i=0;i<n;i++)
			temp[i] = false;
		for(int i=0;i<n;i++){
			if(i==0){
				if(def[i] > att[n-1]+att[i+1])
					temp[i] = true;
			}
			if(i!=0 && i!=n-1 &&(def[i] > att[i-1]+att[i+1])){
					temp[i] = true;
				//	cout<<"you brutus\n";
			}
				
			if(i == n-1)	{
				//cout<<def[i]<<" "<<att[i-1]<<" "<<att[0]<<endl;
					if(def[i] > att[i-1]+att[0]){
						temp[i] = true;
				//		cout<<"why\n";
					}
					
			}	
		}	
		bool res = false;
		llt ind=0,ans=0;	
		for(int i=0;i<n;i++){
			if(temp[i]){
				res=true;
				ans=max(ans,def[i]);
			
			}
	}
	if(res)
		cout<<ans<<endl;
	else cout<<-1<<endl;	
}
}
