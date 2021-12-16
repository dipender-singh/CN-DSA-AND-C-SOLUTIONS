#include<bits/stdc++.h>
using namespace std;
void print(int n){
    if(n == 1){
        cout << n << " ";
    }
    if(n > 1){
    cout << n << " ";
    print(n - 1);
}
}
int main(){
	int n;
	cin>>n;
	print(n);
}
