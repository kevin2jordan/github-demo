#include<bits/stdc++.h>
using namespace std;
void sol1(int arr[],int n){
	cout<<"_, ";
	int j ;
	for(int i=1;i<n;i++){
		for(j=i;j>=0;j--){
			if(arr[j]<arr[i]){
				cout<<arr[j]<<", ";
				break;
			}
		}
		if(j== -1)
			cout<<"_, ";
	}
}
void sol2(int arr[],int n){
	stack<int> st;
	for(int i=0;i<n;i++){
		while(!st.empty() && st.top() >= arr[i]){
			cout<<"arr "<<arr[i]<<" "<<st.top()<<endl;
			st.pop();
	
		}
			
		if(st.empty()){
		//	cout<<"_, ";
		}	
		else{
		//	cout<<st.top()<<", ";
		}
		st.push(arr[i]);
	}
}
int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	//sol1(arr,n);
	sol2(arr,n);
}
