#include <bits/stdc++.h>
using namespace std;

int lcs(string s, string t) {
		// Base case
	if(s.size() == 0 || t.size() == 0) {
		return 0;
	}

		// Recursive calls
	if(s[0] == t[0]) {
		return 1 + lcs(s.substr(1), t.substr(1));
	}
	else {

		int a = lcs(s.substr(1), t);
		int b = lcs(s, t.substr(1));
		int c = lcs(s.substr(1), t.substr(1)); //this case can be removed because this case will get repeated in other two cases
		return max(a, max(b, c));
	}
}
int main(){
	string s,t;
	cout<<"Enter the string 1\n";
	cin>>s;
	//cout<<s<<"\n";
	cout<<"Enter the string 2\n";
	cin>>t;
	//cout<<t<<"\n";
	int ans = lcs(s,t);
	cout<<"Length of the longest common subsequence is: "<<ans<<endl;
	return 0;
}









