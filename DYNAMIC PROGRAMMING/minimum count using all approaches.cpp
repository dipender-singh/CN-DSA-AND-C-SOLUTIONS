/*
Code : Minimum Count
Send Feedback
Given an integer N, find and return the count of minimum numbers required to represent N as a sum of squares.
That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. The output will be 1, as 1 is the minimum count of numbers required to represent N as sum of squares.
Input format :
The first and the only line of input contains an integer value, 'N'.
 Output format :
Print the minimum count of numbers required.
Constraints :
0 <= n <= 10 ^ 4

Time Limit: 1 sec
Sample Input 1 :
12
Sample Output 1 :
3
Explanation of Sample Output 1 :
12 can be represented as : 
A) (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2)

B) (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2)  + (2 ^ 2)

C) (1^2) + (1^2) + (1^2) + (1^2) + (2 ^ 2) + (2 ^ 2)

D) (2 ^ 2) + (2 ^ 2) + (2 ^ 2)

As we can see, the output should be 3.
Sample Input 2 :
9
Sample Output 2 :
1
*/
int minCount(int n)
{
	//Write your code here
    /*
    //my recursive solution was this
    //base case
    int x = sqrt(n);
    if( x^x == n){
        return 1;
    }
    if(n<=3){ // kyunki 3 aur 3 se neeche kisi bhi number ka koi perfect square availabe nahi hai
        return n;
    }
    int res=n; // maxmimum number of squares are that of one 1^2 + 1^2 + 1^2...... = n
    for(int i = 1 ; i  <=n ; i++ ){ //this for loop is used to calculate minimum number of squares required to come from 1 to that specific number
        int temp = i*i;
        if(temp>n){
            break;
        }
        res = min(res,1 + minCount(n-temp));
     }
    return res;
     */
    //this 
    int *ans= new int[n+1];
    ans[0]=0;
    ans[1]=1;
    ans[2]=2;
    ans[3]=3;
    for(int i = 4 ; i <= n ; i++){
       ans[i]=i;
        
        for(int x =1 ; x <= i ; x++){
            int temp = x*x;
            if(temp > i){
                break;
            }
            ans[i] = min(ans[i],1+ans[i-temp]);
        }
    }
    return ans[n];
}

