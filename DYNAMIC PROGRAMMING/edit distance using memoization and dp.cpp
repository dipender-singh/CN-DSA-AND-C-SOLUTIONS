/*
Code : Edit Distance (Memoization and DP)
Send Feedback
You are given two strings S and T of lengths M and N, respectively. Find the 'Edit Distance' between the strings.
Edit Distance of two strings is the minimum number of steps required to make one string equal to the other. In order to do so, you can perform the following three operations:
1. Delete a character
2. Replace a character with another one
3. Insert a character
Note :
Strings don't contain spaces in between.
 Input format :
The first line of input contains the string S of length M.

The second line of the input contains the String T of length N.
Output format :
Print the minimum 'Edit Distance' between the strings.
Constraints :
0 <= M <= 10 ^ 3
0 <= N <= 10 ^ 3

Time Limit: 1 sec
Sample Input 1 :
abc
dc
Sample Output 1 :
2
 Explanation to the Sample Input 1 :
 In 2 operations we can make string T to look like string S.
First, insert character 'a' to string T, which makes it "adc".

And secondly, replace the character 'd' of string T with 'b' from the string S. This would make string T as "abc" which is also string S. 

Hence, the minimum distance.
Sample Input 2 :
whgtdwhgtdg
aswcfg
Sample Output 2 :
9
*/
#include<bits/stdc++.h>
/*MEMOIZATION APPROACH
int editDistance(string s1 , string s2 , int **output){
    if(s1.size() == 0 || s2.size()==0){
        return max( s1.size() , s2.size() );
    }
    int m = s1.size();
    int n = s2.size();
    int ans; 
    if(output[m][n]!=-1){
        return output[m][n];
    }
    if( s1[0] == s2[0] ){
        ans = editDistance( s1.substr(1) , s2.substr(1) , output );
    }
    else{
        int i = 1 + editDistance(s1.substr(1) , s2, output);
        int d = 1 + editDistance(s1 , s2.substr(1) , output);
        int u = 1 + editDistance(s1.substr(1) , s2.substr(1) , output);
        ans = min(i,min(d,u));  
    }
    output[m][n] = ans;
    return ans;
}
int editDistance(string s1, string s2)
{
	//Write your code here
    int m = s1.size();
    int n = s2.size();
    int **ans = new int*[m+1];
    for(int i = 0 ; i <=m ;i++){
       ans[i] = new int[n+1];
        for(int j = 0 ; j <=m ;j++){
        ans[i][j] = -1; 
        }
    }
    return editDistance(s1,s2,ans);
}
*/
// DYNAMIC PROGRAMMING APPROACH
int editDistance(string s1, string s2)
{
	//Write your code here
    int m = s1.size();
    int n = s2.size();
    int **ans = new int*[m+1];
    for(int i = 0 ; i <=m ;i++){
       ans[i] = new int[n+1];
        }
    //fill the first row
    for(int j = 0 ; j <= n; j++){
        ans[0][j] = j;
    }
    //fill the first column
    for(int i =1 ; i<=m ; i++){
        ans[i][0] = i;
    }
    for(int i = 1 ; i <=m ;i++){
        for(int j = 1 ; j<=n ; j++){
            if(s1[m-i]==s2[n-j]){
                ans[i][j] = ans[i-1][j-1];
            }
            else{
                int a = ans[i-1][j];
                int b = ans[i][j-1];
                int c = ans[i-1][j-1];
                ans[i][j] = min(a , min(b,c))+1;
            
            }
        }
    }
    return ans[m][n];
}
