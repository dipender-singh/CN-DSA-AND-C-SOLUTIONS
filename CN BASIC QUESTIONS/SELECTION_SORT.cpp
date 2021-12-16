#include <bits/stdc++.h>
using namespace std;
int selectionsort(int a[],int n){
	int min=0,temp=0;
	for(int i=0;i<n-1;i++){
		min=i;
		for(int j=i+1;j<n;j++){
			if(a[j]<a[min]){
			min=j;
		}
		}
		if(i!=min){
			temp=a[i];
			a[i]=a[min];
			a[min]=temp;
		}
	}
	for(int i=0;i<n;i++){
		cout<<a[i];
	}
}
int main() {
	// your code goes here
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	selectionsort(a,n);
	return 0;
}
