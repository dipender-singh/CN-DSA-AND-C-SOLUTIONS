#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int input[n];
	for(int i=0;i<n;i++){
		cin>>input[i];
	}
	 int a=0,t=input[0],p=0;
    for(int i=0;i<n;i++){
        if(input[i]<t){
            a=input[i];
            p=i;
        }
    }
    cout<<p<<endl;
}
