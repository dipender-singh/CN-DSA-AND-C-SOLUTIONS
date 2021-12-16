/*
Code: Knapsack (Memoization and DP)
Send Feedback
A thief is robbing a store and can carry a maximal weight of W into his knapsack. There are N items and ith item weighs wi and is of value vi. Considering the constraints of maximum weight that knapsack can carry, you have to find and return the maximum value that thief can generate by stealing items.
Note
Space complexity should be O(W).
Input Format :
The first line contains an integers, that denote the value of N. The following line contains N space separated integers, that denote the values of weight of items. The following line contains N space separated integers, that denote the values associated with the items. The following line contains an integer that denote the value of W. W denotes maximum weight that thief can carry.
Output Format :
The first and only line of output contains the maximum value that thief can generate, as described in the task. 
Constraints
1 <= N <= 10^4
1<= wi <= 100
1 <= vi <= 100
Time Limit: 1 second
Sample Input 1 :
4
1 2 4 5
5 4 8 6
5
Sample Output 1 :
13
*/
#include<bits/stdc++.h>
/*int knapsack_mem(int* weight, int* value, int n, int maxWeight,int** dp) {
	// Write your code here
    //MEMOIZATION
   if(n==0|| maxWeight==0){
       return 0;
   }
    if(dp[n][maxWeight]!=-1){
        return dp[n][maxWeight];
    }
    if(weight[0]>maxWeight){
        return dp[n][maxWeight] = knapsack_mem(weight+1,value+1,n-1,maxWeight,dp);
    }
    else{
       return dp[n][maxWeight]=max(value[0]+knapsack_mem(weight+1,value+1,n-1,maxWeight-weight[0],dp),knapsack_mem(weight+1,value+1,n-1,maxWeight,dp));
        //dp[n][maxWeight]
    }
}
int knapsack(int* weight, int* value, int n, int maxWeight){
    int** dp;
    dp = new int*[n];
 
    // loop to create the table dynamically
    for (int i = 0; i < n; i++)
        dp[i] = new int[maxWeight + 1];
 
    // loop to initially filled the
    // table with -1
    for (int i = 0; i < n; i++)
        for (int j = 0; j < maxWeight + 1; j++)
            dp[i][j] = -1;
    return knapsack_mem(weight , value , n , maxWeight , dp);
}*/
//DYNAMIC PROGRAMMING APPROACH WITH A 1-D ARRAY (BEST SOLUTION IS THIS ONE)
int knapsack(int* weight, int* value, int n, int maxWeight){
     int dp[maxWeight + 1];
    memset(dp, 0, sizeof(dp));
 
    for (int i = 1; i < n + 1; i++) {
        for (int w = maxWeight; w >= 0; w--) {
 
            if (weight[i - 1] <= w)
                // finding the maximum value
                dp[w] = max(dp[w],
                            dp[w - weight[i - 1]] + value[i - 1]);
        }
    }
    return dp[maxWeight];
}
