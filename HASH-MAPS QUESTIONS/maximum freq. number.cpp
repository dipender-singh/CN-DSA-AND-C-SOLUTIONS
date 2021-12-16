/*
Code : Maximum Frequency Number
Send Feedback
You are given an array of integers that contain numbers in random order. Write a program to find and return the number which occurs the maximum times in the given input.
If two or more elements contend for the maximum frequency, return the element which occurs in the array first.
Input Format:
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol N.
The following line contains N space separated integers, that denote the value of the elements of the array.
Output Format :
The first and only line of output contains most frequent element in the given array.
Constraints:
0 <= N <= 10^8
Time Limit: 1 sec
Sample Input 1 :
13
2 12 2 11 12 2 1 2 2 11 12 2 6 
Sample Output 1 :
2
Sample Input 2 :
3
1 4 5
Sample Output 2 :
1
*/
#include<bits/stdc++.h>
//#include<map>
int highestFrequency(int arr[], int n) {
    // Write your code here
    if( n==0 ){
        return 0;
    }
    map< int , int > m;
    for(int i = 0 ; i < n ; i++){
        m[arr[i]]++;
    }
   int max_count = 0 , res = -1;
    for( int i = 0 ; i < m.size() ; i++){
        if( m[i] > max_count ){
            res = i;
            max_count = m[i];
        }
    }
    // return res;
    for(int i=0;i<m.size();i++){
        
        if(m[arr[i]]==max_count){
            return arr[i];
        }
        
    }
}
