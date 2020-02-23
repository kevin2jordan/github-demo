#include<iostream>
using namespace std;

void merged_value(int a[],int l,int mid,int r){
	int n1=mid-l+1;
	int n2=r-mid;
	int a1[n1],a2[n2];
	for(int i=0;i<n1;i++)a1[i]=a[l+i];
	for(int i=0;i<n2;i++)a2[i]=a[mid+i+1];
	int k=l;
	int i=0,j=0;
	while(i<n1 && j<n2){
		if(a1[i]<a2[j]){
			a[k]=a1[i];
			i++;
			k++;
		}
		else{
			a[k]=a2[j];
			j++;
			k++;
		}
	}
	while(i<n1){
		a[k]=a1[i];
		i++;
		k++;
	}
	while(j<n2){
		a[k]=a2[j];
		j++;
		k++;
	}
}
void merge_sort(int a[],int l,int r){
	if(l<r){
		int mid=(l+r)/2;
		merge_sort(a,l,mid);
		merge_sort(a,mid+1,r);
		merged_value(a,l,mid,r);
	}
}

int calculate_lr(int a[],int n,int k){
	int sum=0;
	for(int i=0;i<k;i++)sum+=a[i];
	int t=a[k-1]*(n-k);
	sum+=t;
	return sum;
}
int calculate_rl(int a[],int n,int k){
	int sum=0;
	for(int i=n-1;i>=(n-k);i--)sum+=a[i];
	return sum;
}

int main(){
	int test;
	cin>>test;
	while(test--){
		int n,k;
		cin>>n>>k;
		int a[n];
		for(int i=0;i<n;i++)cin>>a[i];
		if(k>=n || k<=0)cout<<"0"<<endl;
		else{
			merge_sort(a,0,n-1);
			// for(int i=0;i<n;i++)cout<<a[i]<<" ";
			// cout<<endl;
			int lr=calculate_lr(a,n,k);
			//cout<<"lr = "<<lr<<endl;
			int rl=calculate_rl(a,n,k);
			//cout<<"rl = "<<rl<<endl;
			cout<<min(lr,rl)<<endl;
		}
	}
	return 0;
}