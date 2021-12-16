/*
Rat In A Maze Problem
Send Feedback
You are given an integer N and a binary 2D array of size N*N. The given binary matrix represents a maze and a rat starts from the top left cell and has to reach to the bottom right cell of the maze. The rat can move in all the four directions: up, down, left and right.
In the given binary matrix, 0 signifies the cell is a dead end and 1 signifies the cell can be used to move from source to destination cell.
You have to print all the paths, following which rat can move from the top left cell to the bottom right cell of the given binary matrix.
Input Format
The first line of input contains an integer, that denotes the value of N.
Each of the following N lines denote rows of the binary matrix and contains either 0 or 1. Each row of the binary matrix contains N elements. 
Output Format :
Every possible solution has to be printed on a separate line. Each of the possible solution will have N*N elements, printed row wise and separated by space. The cells that are part of the path should be 1 and remaining all cells should be 0. Please refer to sample test cases for more clarity.   
Constraints
1 <= N <= 18
0 <= Number of cells with value 1 <= 15
Time Limit: 1 second
Sample Input 1 :
3
1 0 1
1 0 1
1 1 1
Sample Output 1 :
1 0 0 1 0 0 1 1 1 
Explanation :
Only 1 path is possible. The path is shown in the image below.
Alt Text

Sample Input 2 :
3
1 0 1
1 1 1
1 1 1
Sample Output 2 :
1 0 0 1 1 1 1 1 1 
1 0 0 1 0 0 1 1 1 
1 0 0 1 1 0 0 1 1 
1 0 0 1 1 1 0 0 1 
Explanation:
 As described in the Sample Output 2, four paths are possible.
 */
 /*
	Note:
	To get all the test cases accepted, make recursive calls in following order: Top, Down, Left, Right.
	This means that if the current cell is (x, y), then order of calls should be: top cell (x-1, y), 
	down cell (x+1, y), left cell (x, y-1) and right cell (x, y+1).
*/

#include<iostream>
using namespace std;

void print(int **out,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<out[i][j]<<" ";
        }
    }
    cout<<endl;
}

void get_ans(int maze[][20],int n,int **out, int i,int j){
    if(i>=n||j>=n||i<0||j<0){ //limits crossed
        return;
    }
    else if(out[i][j]==1){ //cell already taken in path
        return;
    }
    else if(i==n-1&&j==n-1){ //reached destination
        //make destination as 1
        out[n-1][n-1]=1;
        print(out,n);
        //reset destination for backtracking - not required for destination point btw
        out[n-1][n-1]=0;
        return;
    }
    else if(maze[i][j]==0){ //reached a block
        return;
    }
    else{
        //maze[i][j]==1
        
        out[i][j]=1; //start path
        // i can go to 4 directions L,R,U,D
        
        //left call
        get_ans(maze,n,out,i,j-1);
        //right call
        get_ans(maze,n,out,i,j+1);
        //up call
        get_ans(maze,n,out,i-1,j);
        //down call
        get_ans(maze,n,out,i+1,j);
        
        //backtrack - revert the paths
        out[i][j]=0;
        
    }
}

void ratInAMaze(int maze[][20], int n){

	int **out=new int*[n];
    for(int i=0;i<n;i++){
        out[i]=new int[n];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            out[i][j]=0;
        }
    }
    get_ans(maze,n,out,0,0);
    for(int i=0;i<n;i++){
        delete out[i];
    }
    delete out;
    
}

int main(){

  int n; 
  cout<<"Enter the size for the maze\n";
  cin >> n ;
  int maze[20][20];
  cout<<"Enter the maze configuration\n";
  for(int i = 0; i < n ;i++){
	for(int j = 0; j < n; j++){
        	cin >> maze[i][j];
        }		
  }
  ratInAMaze(maze, n);
}
/*
#include<bits/stdc++.h>
using namespace std;

void print(int **ans, int n){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cout<<ans[i][j]<<" ";
        }
        //cout<<endl;
    }
cout<<endl;
}

void getans(int maze[][20] , int **ans , int n, int i , int j){
    if(i>=n || j>=n || i<0 || j<0){
        return ;
    }
    else if(ans[i][j]==1){
        return;
    }
    else if(i==n-1 && j==n-1){
        ans[i][j]=1;
        print(ans,n);
        ans[i][j]=0;
        return;
    }
    else if(ans[i][j]==0) {
        return;
    }
    else{
        ans[i][j]=1;  //iska matlab hum is point pe visit kar gaye hain
        getans(maze,ans,n,i-1,j); // up jane ke liye call
        getans(maze,ans,n,i+1,j); // down jane ke liye call
        getans(maze,ans,n,i,j-1); // left jane ke liye call
        getans(maze,ans,n,i,j+1); // right jane ke liye call
        ans[i][j]=0;
    }
}

void ratinamaze(int maze[][20], int n){
    int **ans = new int*[n];
    for(int i = 0 ; i < n ; i++){
        ans[i] = new int[n];
        for(int j = 0; j < n  ; j++){
            ans[i][j]=0;
        }
    }
    getans(maze,ans,n,0,0);
}

int main(){
    int n;
    cin>>n;
    int maze[20][20];
    for(int i = 0 ; i<  n ; i++){
        for(int j=0;j<n;j++){
            cin>>maze[i][j];
        }
    }
    ratinamaze(maze,n);
}
*/
