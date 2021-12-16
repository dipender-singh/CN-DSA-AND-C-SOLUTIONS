//THIS QUESTION IS BASICALLY MERGE SORT
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,t=0,temp=0;
	cin>>n;
	int a[n];
	int x;
	cin>>x;
	int b[x];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<x;i++){
		cin>>b[i];
	}
	int r=n+x;
	int c[r];
	/*for(int i=0,j=0,k=0;i<n,j<x,k<r;i++,j++){
		if(a[i]<b[j]){
			c[k]=a[i];
			c[k+1]=b[j];
			k+=2;
		}
		else{
			c[k]=b[j];
			c[k+1]=a[i];
			k+=2;
		}
	}
		for(int i=0;i<r;i++){
		cout<<c[i];
	}*/
	int g=0,h=0,k=0;
	while(g<n && h<x){
		if(a[g] < b[h]){
			c[k]=a[g];
			k++;
			g++;
		}
		else{
			c[k]=b[h];
			k++;
			h++;
		}
	}
	while(g<n){
		c[k]=a[g];
		k++;
		g++;
	}
	while(h<x){
		c[k]=b[h];
		k++;
		h++;
	}
}
