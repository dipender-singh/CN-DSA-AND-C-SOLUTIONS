#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m=0;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		int k=a[i];
		for(int j=i;j<n;j++){
			if(k<a[j]){
				k=a[j];
			}
		}
		cout<<k<<" ";
	}
}
