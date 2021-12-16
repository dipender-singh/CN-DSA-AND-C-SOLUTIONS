/*
Coding Ninjas
Send Feedback
Given a NxM matrix containing Uppercase English Alphabets only. Your task is to tell if there is a path in the given matrix which makes the sentence �CODINGNINJA� .
There is a path from any cell to all its neighbouring cells. For a particular cell, neighbouring cells are those cells that share an edge or a corner with the cell.
Input Format :
The first line of input contains two space separated integers N and M, where N is number of rows and M is the number of columns in the matrix. 
Each of the following N lines contain M characters. Please note that characters are not space separated.
Output Format :
Print 1 if there is a path which makes the sentence �CODINGNINJA� else print 0.
Constraints :
1 <= N <= 1000
1 <= M <= 1000
Time Limit: 1 second
Sample Input 1:
2 11
CXDXNXNXNXA
XOXIXGXIXJX
Sample Output 1:
1
*/
#include<bits/stdc++.h>
bool bfs( vector< vector<char> > &board , int n , int m ,int ci , int cj,vector< vector<bool> >&visited,string s)
{
    if(s.size()==0)
    {
        return true;
    }
    visited[ci][cj]=true;


    bool ans = false;
    if(ci+1<n && !visited[ci+1][cj] && board[ci+1][cj]==s[0])// down
    {
        if( bfs(board,n,m,ci+1,cj,visited, s.substr(1)))
            return true;
    }

    if(ci-1>=0 && !visited[ci-1][cj] && board[ci-1][cj]==s[0])// up

    {
        if(  	bfs(board,n,m,ci-1,cj,visited, s.substr(1)))
            return true;
    }
    if(cj-1>=0 && !visited[ci][cj-1] && board[ci][cj-1]==s[0])// left
    {
        if( bfs(board,n,m,ci,cj-1,visited, s.substr(1)))
            return true;
    }

    if(cj+1<m && !visited[ci][cj+1] && board[ci][cj+1]==s[0])// right
    {
        if( bfs(board,n,m,ci,cj+1,visited, s.substr(1)))
            return true;
    }


    if(ci+1<n && cj-1>=0&&!visited[ci+1][cj-1] && board[ci+1][cj-1]==s[0])// down left
    {
        if( bfs(board,n,m,ci+1,cj-1,visited, s.substr(1)))
            return true;
    }

    if(ci+1<n && cj+1<m&&!visited[ci+1][cj+1] && board[ci+1][cj+1]==s[0])// down right
    {
        if( bfs(board,n,m,ci+1,cj+1,visited, s.substr(1)))
            return true;
    }


    if(ci-1>=0 && cj-1>=0 && !visited[ci-1][cj-1] && board[ci-1][cj-1]==s[0])// up left 
    {
        if( bfs(board,n,m,ci-1,cj-1,visited, s.substr(1)))
            return true;
    }

    if(ci-1>=0 && cj+1<m&& !visited[ci-1][cj+1] && board[ci-1][cj+1]==s[0])// up right
    {
        if(	 bfs(board,n,m,ci-1,cj+1,visited, s.substr(1)))
            return true;
    }
    
 visited[ci][cj]=false;

    return ans;
}




bool hasPath(vector<vector<char>> &board, int n, int m) {
vector<vector<bool> >visited(n,vector<bool>(m, false));
    for(int i=0; i<n ; i++)
    {    for(int j=0 ; j< m; j++)
    {
        if(board[i][j]=='C')
        {
            
            string s ="ODINGNINJA";
       
            if(bfs(board, n,m,i,j,visited,s))
                return true;

        }
    }
    }
    return false;

}
