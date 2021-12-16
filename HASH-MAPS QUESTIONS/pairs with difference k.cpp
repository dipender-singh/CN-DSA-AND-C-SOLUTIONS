/*
Pairs with difference K
Send Feedback
You are given with an array of integers and an integer K. You have to find and print the count of all such pairs which have difference K.
Note: Take absolute difference between the elements of the array.
Input Format:
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol n.
The following line contains n space separated integers, that denote the value of the elements of the array.
The following line contains an integer, that denotes the value of K.
Output format :
The first and only line of output contains count of all such pairs which have an absolute difference of K. 
Constraints :
0 <= n <= 10^4
Time Limit: 1 sec
Sample Input 1 :
4 
5 1 2 4
3
Sample Output 1 :
2
Sample Input 2 :
4
4 4 4 4 
0
Sample Output 2 :
6
*/
#include<bits/stdc++.h>
int getPairsWithDifferenceK(int *arr, int n, int k) {
	// Write your code here
    if(n==0){
        return 0;
    }
    unordered_map< int , int >m;
	int ans=0;
    for(int i=0;i<n;i++)
    {
        int op1=arr[i]+k;
        int op2=arr[i]-k;
        ans+=m[op1]; //ab yahan pe map mein initally kuch insert hua nahi hai so ye by deafult 0 value ke
        if(k!=0)
            ans+=m[op2];
        m[arr[i]]++;
    }
    return ans;
}
