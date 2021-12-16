/*
3 Cycle
Send Feedback
Given a graph with N vertices (numbered from 0 to N-1) and M undirected edges, then count the distinct 3-cycles in the graph. A 3-cycle PQR is a cycle in which (P,Q), (Q,R) and (R,P) are connected by an edge.
Input Format :
The first line of input contains two space separated integers, that denotes the value of N and M.
Each of the following M lines contain two integers, that denote the vertices which have an undirected edge between them. Let us denote the two vertices with the symbol u and v. 
Output Format :
Print the count the number of 3-cycles in the given graph
Constraints :
0 <= N <= 100
0 <= M <= (N*(N-1))/2
0 <= u <= N - 1
0 <= v <= N - 1
Time Limit: 1 sec
Sample Input 1:
3 3
0 1
1 2
2 0
Sample Output 1:
1
*/
#include <bits/stdc++.h>
using namespace std;

int solve(bool **edge,int n){
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(edge[i][j] && i!=j){
                for(int k=0;k<n;k++){
                    if(j!=k && k!=i && edge[j][k] && edge[i][k]){
                        count++;
                    }
                }
            }
        }
    }
    return count/6;
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
    cout<<solve(edge,n);
}
