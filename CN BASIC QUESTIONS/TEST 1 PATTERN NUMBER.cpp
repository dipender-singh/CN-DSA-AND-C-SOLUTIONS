#include<bits/stdc++.h>
using namespace std;

int main() {
int n;
    cin>>n;
    int i=1;
    int k,j,x;
    while(i<=n){
    	k=n-i;
    	while(k>0){
    		cout<<" ";
    		k--;
		}
		for(j=i;j>=1;j--){
			cout<<j;
		}
		x=2;
		while(x<=i){
			cout<<x;
			x++;
		}
		cout<<endl;
		i++;
	}
}

