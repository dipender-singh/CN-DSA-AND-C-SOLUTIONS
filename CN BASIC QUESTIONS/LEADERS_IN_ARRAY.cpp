#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m=0;
	cin>>n;
	int a[n];
	int b[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int k=a[n-1];
	int j=1;
	b[0] = k;
	for(int i=n-2;i>=0;i--){
		if(a[i]>k){
			k=a[i];
			b[j]=k;
			j++;
		}
}
    for(int i=sizeof(b)-1;i>=0;i--){
    	cout<<b[i]<<" ";
	}
}
