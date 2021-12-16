/*
Code : Is Connected ?
Send Feedback
Given an undirected graph G(V,E), check if the graph G is connected graph or not.
Note:
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.
Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two integers, that denote that there exists an edge between vertex a and b.
Output Format :
The first and only line of output contains "true" if the given graph is connected or "false", otherwise.
Constraints :
0 <= V <= 1000
0 <= E <= (V * (V - 1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1
Time Limit: 1 second
Sample Input 1:
4 4
0 1
0 3
1 2
2 3
Sample Output 1:
true
Sample Input 2:
4 3
0 1
1 3 
0 3
Sample Output 2:
false 
Sample Output 2 Explanation
The graph is not connected, even though vertices 0,1 and 3 are connected to each other but there isn’t any path from vertices 0,1,3 to vertex 2. 
*/
#include <bits/stdc++.h>
using namespace std;


bool getBFS(int **edges, int n , int start , bool *visited){
   queue<int> q;
    q.push(start);
    visited[start]=true;
    while(!q.empty()){
    int t = q.front();
        q.pop();
        for(int  i = 0 ; i < n ; i++){
            if(edges[t][i]==1 && !visited[i]){
            q.push(i);
            visited[i]=true;
            }
        }
    }
    for(int i = 0 ; i < n ; i++){
        if(visited[i]==false){
         return false;   
        }
    }
    return true;
}


int main() {
    // Write your code here
     int n,e;  //n->vertices,e->edges
    cin>>n>>e;
    int **edges=new int*[n];  //edges array(2D)
    for(int i=0;i<n;i++){
        edges[i]=new int[n];
        for(int j=0;j<n;j++){
            edges[i][j]=0;
        }
    }
    //taking input of edges
    for(int i=0;i<e;i++){
        int f,s;
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }
    //visited array
    bool *visited=new bool[n];
    memset(visited,false,sizeof(visited));
    //call your working function below
    bool ans = getBFS(edges,n,0,visited);
    if(ans==true){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
}
