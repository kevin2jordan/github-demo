
#include<bits/stdc++.h>
using namespace std;
bool checkSol1(int arr[], int n,int sum){
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			//cout<<arr[i]<<" "<<arr[j]<<endl;
			if(arr[i]*arr[j] == sum)
				return true;
		}
	}
	return false;
}
bool checkSol2(int arr[],int n,int sum){
	unordered_set<int> st;
	for(int i=0;i<n;i++){
		if(st.find(sum/arr[i])!=st.end()){
			cout<<arr[i]<<" "<<sum/arr[i]<<endl;
		}
		else st.insert(arr[i]);
	}
	return true;
}
int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	int sum;
	cin >> sum;
	checkSol2(arr,n,sum)?cout<<"Yes\n":cout<<"No\n";
	
}
