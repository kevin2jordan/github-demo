#include<bits/stdc++.h>
using namespace std;
int trappedRain(int arr[],int n){
	int leftMax[n];
	int rightMax[n];
	int ans=0;
	for(int i=0;i<n;i++)
		leftMax[i]=0;
	for(int j=0;j<n;j++)
		rightMax[j]=0;	
	leftMax[0] = arr[0];
	rightMax[n-1] = arr[n-1];
	
	for(int i=1;i<n;i++)
		leftMax[i] = max(leftMax[i-1],arr[i]);
	for(int j=n-2;j>=0;j--)
		rightMax[j] = max(arr[j],rightMax[j+1]);
		
		
//	for(int i=0;i<n;i++)
//	cout<<leftMax[i]<<" ";
//	cout<<endl<<endl;
//	for(int j=0;j<n;j++)
//		cout<<rightMax[j]<<" ";
			
	for(int i=0;i<n;i++)
		ans+=min(leftMax[i],rightMax[i])-arr[i];	
	return ans;		
}
int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin >> arr[i];
	cout<<trappedRain(arr,n);	
}
