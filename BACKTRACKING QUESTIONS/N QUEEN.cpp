/*
N-Queen Problem
Send Feedback
You are given N, and for a given N x N chessboard, find a way to place N queens such that no queen can attack any other queen on the chess board. A queen can be killed when it lies in the same row, or same column, or the same diagonal of any of the other queens. You have to print all such configurations.
Note: Don't print anything if there isn't any valid configuration.
Input Format:
The first line of input contains an integer, that denotes the value of N.     
Output Format :
In the output, you have to print every board configuration in a new line. Every configuration will have N*N board elements printed row wise and are separated by space. The cells where queens are safe and placed, are denoted by value 1 and remaining all cells are denoted by value 0. Please refer to sample test cases for more clarity.
Constraints :
1 <= N <= 10
Time Limit: 1 second
Sample Input 1:
4
Sample Output 1 :
0 1 0 0 0 0 0 1 1 0 0 0 0 0 1 0 
0 0 1 0 1 0 0 0 0 0 0 1 0 1 0 0 
Explanation:
The first and second configuration are shown in the image below. Here, 1 denotes the placement of a queen and 0 denotes an empty cell. Please note that in both the configurations, no pair of queens can kill each other. 
Alt Text
*/
/* BASIC SOLUTION
bool isSafe(int row , int col , vector<string> *board, int n){
    int duprow = row;
    int dupcol = col;
    while(row >= 0 && col >= 0 ){
        if(board[row][col]=='Q'){
            return false;
        }
        row--;
        col--;
    }

 row=duprow;
    col=dupcol;
    while(col>=0){
        if(board[row][col]=='Q'){
            return false;
        }
        col--;
    }
    row=duprow;
    col=dupcol;
    while(row <= n-1 && col<=n-1 ){
        if(board[row][col]=='Q'){
            return false;
        }
        row++;
        col++;
    }
    return true; // iska matlab ye hai ki mujhe teeno hi directions mein koi bhi Qc pehle se padha hua nahi mila hai
}


void solve(int col , vector<string> *board , vecotr<vector<string>> *ans , int n){
    if(col==n){
        ans.push_back(board);
        return;
    }
    for(int row = 0 , row < n , row++){
        if(isSafe(row,col,board,n)){
         board[row][col]='Q';
            solve(col+1,board,ans,n);
            board[row][col]='.';
        }
    }
}


int main(){    
    // write your code here
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n,'.');
    for(int i = 0 ; i < n ; i++){
        board[i]=s;
    }
    solve(0,board,ans,n);
    return ans;
}
*/
/* STRIVERS EFFICIENT APPROACH
 void solve(int col, vector<string> &board, vector<vector<string>> &ans, 
               vector<int> &leftRow, 
               vector<int> &upperDiagonal, vector<int> &lowerDiagonal, int n) {
        if(col == n) {
            ans.push_back(board); 
            return; 
        }
    
        
        for(int row = 0;row<n;row++) {
            if(leftRow[row]==0 && lowerDiagonal[row + col] == 0 
               && upperDiagonal[n-1 + col - row] == 0) {
                
                board[row][col] = 'Q'; 
                leftRow[row] = 1; 
                lowerDiagonal[row+col] = 1; 
                upperDiagonal[n-1 + col - row] = 1;
                solve(col+1, board, ans, leftRow, upperDiagonal, lowerDiagonal, n); 
                board[row][col] = '.'; 
                leftRow[row] = 0; 
                lowerDiagonal[row+col] = 0; 
                upperDiagonal[n-1 + col - row] = 0;
            }
        }
    }
int main(){
      vector<vector<string>> ans;
    vector<string> board(n);
    string s(n,'.');
    for(int i = 0 ; i < n ; i++){
        board[i]=s;
    }
      vector<int> leftRow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0); 
        solve(0,board, ans, leftRow, upperDiagonal, lowerDiagonal, n); 
    return ans;
}
*/
//int board[q][q];

#include<iostream>
using namespace std;

void print(int **board,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j]<<" ";
       //     cout<<endl;
        }
        cout<<endl;
    }
    cout<<endl;
}

bool ispossible(int **board,int n,int i,int j){
    //check col
    for(int row=0;row<n;row++){
        if(board[row][j]==1){
            return false;
        }
    }
    //check row
    for(int col=0;col<n;col++){
        if(board[i][col]==1){
            return false;
        }
    }
    //check diagonal left bend top
    for(int row=i,col=j;row>=0&&col>=0;row--,col--){
        if(board[row][col]==1){
            return false;
        }
    }
    //check diagonal right bend top
    for(int row=i,col=j;row<n&&row>=0&&col>=0&&col<n;row--,col++){
        if(board[row][col]==1){
            return false;
        }
    }
    return true;
}

void find_all_possible(int **board,int n,int i,int j){
    //crossed limits
    if(i==n){
        print(board,n);
    }
    //check for all cols of a particular row
        for(int col=j;col<n;col++){ //col
            if(ispossible(board,n,i,col)){
                board[i][col]=1;
                find_all_possible(board,n,i+1,0);
                board[i][col]=0;
            }
        }
}

void placeNQueens(int n){
    int **board=new int*[n];
    for(int i=0;i<n;i++){
        board[i]=new int[n];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            board[i][j]=0;
        }
    }
	find_all_possible(board,n,0,0);
    for(int i=0;i<n;i++){
        delete board[i];
    }
    delete board;
}

int main(){

  int n; 
  cin >> n ;
  placeNQueens(n);

}
