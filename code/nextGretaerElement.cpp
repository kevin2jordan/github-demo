#include<bits/stdc++.h>
using namespace std;
void printNextGreaterElement(int arr[],int n){
	stack<int> st;
	st.push(arr[0]);
	for(int i=1;i<n;i++){
		if(!st.empty()){
			while(arr[i]>st.top()){
				cout<<st
			}
		}
	}
}
int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin >> arr[i];
	printNextGreaterElement(arr,n);	
}
