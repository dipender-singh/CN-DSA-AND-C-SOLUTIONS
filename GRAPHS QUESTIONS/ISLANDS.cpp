/*
Islands
Send Feedback
An island is a small piece of land surrounded by water . A group of islands is said to be connected if we can reach from any given island to any other island in the same group . Given V islands (numbered from 1 to V) and E connections or edges between islands. Can you count the number of connected groups of islands.
Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two integers, that denote that there exists an edge between vertex a and b. 
Output Format :
Print the count the number of connected groups of islands
Constraints :
0 <= V <= 1000
0 <= E <= (V * (V-1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1
Time Limit: 1 second
Sample Input 1:
5 8
0 1
0 4
1 2
2 0
2 4
3 0
3 2
4 3
Sample Output 1:
1 
*/
#include <bits/stdc++.h>
using namespace std;
void BFS(bool **edge,int n,int sv,unordered_map<int,bool>& visited){
    queue<int> q;
    q.push(sv);
    visited[sv]=1;
    while(!q.empty()){
        int front=q.front();
        q.pop();
        for(int i=0;i<n;i++){
            if(!visited[i] && edge[front][i] && i!=front){
                q.push(i);
                visited[i]=1;
            }
        }
    }
}
void BFS(bool **edge,int n){
    unordered_map<int,bool> visited;
    for(int i=0;i<n;i++){
        visited[i]=0;
    }
    int ans=0;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            BFS(edge,n,i,visited);
            ans++;
        }
    }
    cout<<ans;
}
int main(){
    int n,e;
    cin>>n>>e;
    bool **edge=new bool*[n];
    for(int i=0;i<n;i++){
        edge[i]=new bool[n];
        for(int j=0;j<n;j++){
            edge[i][j]=0;
        }
    }
    for(int i=0;i<e;i++){
        int f,s;
        cin>>f>>s;
        edge[f][s]=1;
        edge[s][f]=1;
    }
    unordered_map<int,bool> visited;
    for(int i=0;i<n;i++){
        visited[i]=0;
    }
    BFS(edge,n);
    //deleting dynammic memory
    for(int i=0;i<n;i++){
        delete[] edge[i];
    }
    delete[] edge;
}
