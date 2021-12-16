/*
Code : No. of balanced BTs
Send Feedback
Given an integer h, find the possible number of balanced binary trees of height h. You just need to return the count of possible binary trees which are balanced.
This number can be huge, so, return output modulus 10^9 + 7.
Write a simple recursive solution.
Input Format :
The first and only line of input contains an integer, that denotes the value of h. Here, h is the height of the tree.
Output Format :
The first and only line of output contains the count of balanced binary trees modulus 10^9 + 7.
Constraints :
1 <= h <= 24
Time Limit: 1 sec
Sample Input 1:
3
Sample Output 1:
15
Sample Input 2:
4
Sample Output 2:
315
*/
#include<bits/stdc++.h>
int balancedBTs(int n) {
    // Write your code here
   if(n <= 1) {
		return 1;
	}

	int mod = (int) (pow(10, 9)) + 7;
	int x = balancedBTs(n - 1);
	int y = balancedBTs(n - 2);

	int temp1 = (int)(((long)(x)*x) % mod);
	int temp2 = (int)((2* (long)(x) * y) % mod);
	int ans = (temp1 + temp2) % mod;


	//int ans = (x*x + 2*x*y) % mod;
	return ans;
}
