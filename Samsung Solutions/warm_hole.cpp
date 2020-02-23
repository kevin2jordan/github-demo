#include<iostream>
#include<math.h>
using namespace std;
int matrix[1000][1000];
struct pair1{
	int ax;
	int ay;
};
pair1 a[1000];
int visit[1000];
int distance1[1000];

int min_distance(int t){
	int val=99999;
	int index;
	for(int i=0;i<t;i++){
	if(!visit[i] && distance1[i]<=val){
			val=distance1[i];
			index=i;
		}
		if(val==-1)break;
	}
	return index;
}
void calculate(int t){
	for(int j=0;j<t-1;j++){
		int val=min_distance(t);
		visit[val]=1;
		for(int i=0;i<t;i++){
			if(matrix[val][i]!=-1 && !visit[i]){
				if(distance1[i]>distance1[val]+matrix[val][i])
					distance1[i]=distance1[val]+matrix[val][i];
			}
		}
	}
}

int main(){
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		int t=(2*n)+2;
		cin>>a[0].ax>>a[0].ay>>a[t-1].ax>>a[t-1].ay;
		int k=0;
		int w[n];
		for(int i=1;i<t-1;i+=2){
			cin>>a[i].ax>>a[i].ay>>a[i+1].ax>>a[i+1].ay>>w[k];
			k++;
		}
		for(int i=0;i<t;i++)for(int j=0;j<t;j++)matrix[i][j]=-1;
		for(int i=0;i<t;i++){
			for(int j=i+1;j<t;j++){
				int val=abs(a[i].ax-a[j].ax)+abs(a[i].ay-a[j].ay);
				matrix[i][j]=val;
				matrix[j][i]=val;
			}
		}
		k=0;
		for(int i=1;i<t-1;i+=2){
			matrix[i][i+1]=w[k];
			matrix[i+1][i]=w[k];
			k++;
		}
		//for(int i=0;i<t;i++){
		//	for(int j=0;j<t;j++)cout<<matrix[i][j]<<" ";
		//	cout<<endl;
		//}

		for(int i=0;i<t;i++)visit[i]=0;
		for(int i=0;i<t;i++)distance1[i]=99999;
		distance1[0]=0;
		calculate(t);
		//for(int i=0;i<t;i++)cout<<distance1[i]<<" ";
		//cout<<endl;
		cout<<distance1[t-1]<<endl;
	}
	return 0;
}
