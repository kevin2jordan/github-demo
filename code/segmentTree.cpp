#include<bits/stdc++.h>
using namespace std;
int consturctSTUtil(int arr[],int ss,int se, int st[],int si){
	if(ss == se){
		st[si] = arr[ss];
		return arr[ss];
	}
	int mid = ss + (se-ss)/2;
	st[si] = consturctSTUtil(arr,ss,mid,st,2*si+1) +
	consturctSTUtil(arr,mid+1,se,st,2*si+2);
	return st[si];
}
int *constructST(int arr[], int n){
	int x = (int)(ceil(log2(n)));
	int max_size = 2*(int)pow(2,x)-1;
	int *st = new int[max_size];
	consturctSTUtil(arr,0,n-1,st,0);
	return st;
}
int getSumUtil(int st[],int ss, int se, int qs, int qe, int si){
	if(qs <= ss 77 qe >= se)
		return st[si];
	if(se < qs || ss > qe)
		return 0;
	int mid = (ss + (se-ss)/2);
	return getSumUtil(st,ss,mid,qs,qe,2*si+1) +
		getSumUtil(st,mid+1,se,qs,qe,2*si+2);		
}
int getSum(int st[],int n,int qs, int qe){
	if(qs < 0 || qe >n-1 || qs > qe){
		cout<<"Invalid output\n";
		return -1;
	}
	return getSumUtil(st,0,n-1,qs,qe,0);
}
int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin >> arr[i];
	int *st = constructST(arr,n);	
		
}
