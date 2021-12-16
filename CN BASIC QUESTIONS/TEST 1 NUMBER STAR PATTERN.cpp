#include<bits/stdc++.h>
using namespace std;

int main() {
	// Write your code here
int n;
    cin>>n;
    int i=1;
    int k=n;
    int x,a;
    a=n;
    while(i<=n){	
	for(int j=1;j<=k;j++){
		cout<<j;
	}
	int j=2;
	while(j<=i){
		cout<<"*";
		j++;
	}
	int x=2;
	while(x<=i){
		cout<<"*";
		x++;
	}
	 for(int x=a;x>=1;x--){
       cout<<x;
   }
	cout<<endl;
	a--;
	k--;
	i++;
	}
}

