#include<bits/stdc++.h>
using namespace std;
#define llt long long int
//bool prime[n];
//void primeVal(){
//	for(int i=0;i<n;i++)
//		prime[i]=true;
//	prime[0]=false;
//	prime[1]=false;
//	for(int i=2;i<=sqrt(n);i++){
//		if(prime[i]){
//			for(int j=i*i;j<=n;j+=i)
//				prime[j] = false;
//		}
//	}	
//}
bool isPrime(llt n) 
{ 
    // Corner cases 
    if (n <= 1)  return false; 
    if (n <= 3)  return true; 
  
    // This is checked so that we can skip  
    // middle five numbers in below loop 
    if (n%2 == 0 || n%3 == 0) return false; 
  
    for (llt i=5; i*i<=n; i=i+6) 
        if (n%i == 0 || n%(i+2) == 0) 
           return false; 
  
    return true; 
} 
int main(){

	int t;
	cin >> t;
	while(t--){
		string str;
		cin >> str;
		llt temp[256];
		for(int i=0;i<256;i++)
			temp[i]=0;
		for(llt i=0;i<str.length();i++)
			temp[str[i]-'A']++;
//		for(int i=0;i<26;i++)
//			cout<<temp[i]<<" ";	
		vector<llt> vec;
		llt tempSum = str.length();
		for(int i=0;i<256;i++){
			if(temp[i]!=0){
				vec.push_back(temp[i]);
			}
		}	
		llt vecSize = vec.size();
		llt res=0,ans= INT_MAX;
		sort(vec.rbegin(),vec.rend());
		
		
		for(llt i=1;i<=26;i++){
			if(tempSum%i==0){
				//cout<<"inside "<<i<<" "<<tempSum<<" "<<res<<endl;
				llt distCharacter = i;
				llt freqEach = tempSum/i;
				
				if(distCharacter > vecSize)
					res = (distCharacter-vecSize)*freqEach;
				//cout<<"extra character "<<res<<endl;	
			//	cout<<distCharacter<<" "<<freqEach<<" "<<res<<" "<<vecSize<<endl;
				
				
				for(llt j=0;j<min(i,vecSize);j++){
				//	cout<<freqEach<<" "<<vec[j]<<endl;
					if(vec[j] < freqEach)
						res+=freqEach-vec[j];
				}
			
			//	cout<<"After operation "<<res<<endl;
				ans = min(ans,res);	
				res=0;
			}
			
		}
//		
//		if(vecSize == 26 && isPrime(tempSum)){
//			cout<<tempSum-vec[0]<<endl;
//		}
//		else
		 cout<<ans<<endl;
	}
}
