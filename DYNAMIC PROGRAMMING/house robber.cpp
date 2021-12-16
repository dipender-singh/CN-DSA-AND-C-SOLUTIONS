/*
Loot Houses
Send Feedback
A thief wants to loot houses. He knows the amount of money in each house. He cannot loot two consecutive houses. Find the maximum amount of money he can loot.
Input format :
The first line of input contains an integer value of 'n'. It is the total number of houses.

The second line of input contains 'n' integer values separated by a single space denoting the amount of money each house has.
Output format :
Print the the maximum money that can be looted.
Constraints :
0 <= n <= 10 ^ 4

Time Limit: 1 sec
Sample Input 1 :
6
5 5 10 100 10 5
Sample Output 1 :
110
Sample Input 2 :
6
10 2 30 20 3 50
Sample Output 2 :
90
Explanation of Sample Output 2 :
Looting first, third, and the last houses([10 + 30 + 50]) will result in the maximum loot, and all the other possible combinations would result in less than 90.
*/
#include<bits/stdc++.h>
/*int maxMoneyLooted(int *arr, int n)
{
	//Write your code here
    //this is using extra space and now without using extra space
    if(n==0){
        return 0;
    }
    else if(n==1){
        return arr[0];
    }
    else if(n==2){
        return max(arr[0],arr[1]);
    }
    int dp[n];
    dp[0]=arr[0];
    dp[1]=max(arr[1],arr[0]);
   // int ans = 0;
    for(int i = 2 ;i<n ;i++){
            dp[i]=max(arr[i]+arr[i-2],arr[i-1]);
        }
    return dp[n-1];
}*/
// FOR BETTER UNDERSTANDING PURPOSES
//https://www.geeksforgeeks.org/find-maximum-possible-stolen-value-houses/
//https://medium.com/@axionoso/solving-house-robber-algorithm-dynamicprogramming-ad17dc3581cd
int maxMoneyLooted(int *arr, int n){
     if(n==0){
        return 0;
    }
    else if(n==1){
        return arr[0];
    }
    else if(n==2){
        return max(arr[0],arr[1]);
    }
    int ans = 0;
    int val1 = arr[0];
    int val2 = max(arr[0],arr[1]);
    for(int i =2 ; i <n ; i++){
            
            ans = max(arr[i]+val1,val2);
            val1 = val2;
            val2 = ans;
            
    }
    return ans;
}

