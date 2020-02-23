#include<iostream>
using namespace std;
#define ll long long int

void merged(ll a[],ll l,ll mid,ll r){
	ll n1=mid-l+1;
	ll n2=r-mid;
	ll left[n1],right[n2];
	ll j=l;
	for(ll i=0;i<n1;i++)left[i]=a[l+i];
	for(ll i=0;i<n2;i++)right[i]=a[mid+1+i];
	ll l1=0,l2=0;
	while(l1<n1 && l2<n2){
		if(left[l1]<right[l2]){
			a[j]=left[l1];
			j++;
			l1++;
		}
		else{
			a[j]=right[l2];
			j++;
			l2++;
		}
	}
	while(l1<n1){
		a[j]=left[l1];
		l1++;
		j++;
	}
	while(l2<n2){
		a[j]=right[l2];
		l2++;
		j++;
	}
}

void merge_sort(ll a[],ll l,ll r){
	if(l<r){
		ll mid=(l+r)/2;
		merge_sort(a,l,mid);
		merge_sort(a,mid+1,r);
		merged(a,l,mid,r);
	}
}

ll check(ll a[],ll num,ll n,ll c){
	ll cows=1;
	ll pos=a[0];
	for(ll i=1;i<n;i++){
		if(a[i]-pos>=num){
			cows++;
			pos=a[i];
		}
		if(cows==c)return 1;
	}
	return 0;
}

ll b_s(ll a[],ll n,ll c){
	ll l=0;
	ll r=a[n-1];
	ll max1=-1;
	if(c==1)return max1;
	while(l<r){
		ll mid=(l+r)/2;
		if(check(a,mid,n,c)){
			if(mid>max1)max1=mid;
			l=mid+1;
		}
		else r=mid;
	}
	return max1;
}

int main(){
	ll test;
	cin>>test;
	while(test--){
		ll n,cow;
		cin>>n>>cow;
		ll a[n];
		for(ll i=0;i<n;i++)cin>>a[i];
		merge_sort(a,0,n-1);
		//for(ll i=0;i<n;i++)cout<<a[i]<<" ";
		cout<<b_s(a,n,cow)<<endl;
	}
	return 0;
}