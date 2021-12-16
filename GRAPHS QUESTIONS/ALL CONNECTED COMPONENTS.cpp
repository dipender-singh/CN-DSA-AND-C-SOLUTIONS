/*
Code : All connected components
Send Feedback
Given an undirected graph G(V,E), find and print all the connected components of the given graph G.
Note:
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.
3. You need to take input in main and create a function which should return all the connected components. And then print them in the main, not inside function.
Print different components in new line. And each component should be printed in increasing order (separated by space). Order of different components doesn't matter.
Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two space separated integers, that denote that there exists an edge between vertex a and b.
Output Format :
Print different components in new line. And each component should be printed in increasing order of vertices (separated by space). Order of different components doesn't matter.
Constraints :
0 <= V <= 1000
0 <= E <= (V * (V - 1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1
Sample Input 1:
4 2
0 1
2 3
Sample Output 1:
0 1 
2 3 
Sample Input 2:
4 3
0 1
1 3 
0 3
Sample Output 2:
0 1 3 
2
*/
/*#include <bits/stdc++.h>
using namespace std;
vector<int> BFS(bool **edge,int n,int sv,unordered_map<int,bool>& visited){
    queue<int> q;
    q.push(sv);
    visited[sv]=1;
    vector<int> output;
    while(!q.empty()){
        int front=q.front();
        q.pop();
        output.push_back(front);
        for(int i=0;i<n;i++){
            if(!visited[i] && edge[front][i] && i!=front){
                q.push(i);
                visited[i]=1;
            }
        }
    }
    return output;
}
void BFS(bool **edge,int n){
    unordered_map<int,bool> visited;
    for(int i=0;i<n;i++){
        visited[i]=0;
    }
    for(int i=0;i<n;i++){
        if(!visited[i]){
            vector<int> ans=BFS(edge,n,i,visited);
            sort(ans.begin(),ans.end());
            for(int j=0;j<ans.size();j++){
                cout<<ans[j]<<" ";
            }
            cout<<endl;
        }
    }
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
#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

void printDFS(int** graph ,int v,int s,bool* visited ,vector<int> &ans)
{ 
    
  ans.push_back(s);
    visited[s]= true;
    
    for(int i =0 ;i< v ;i++)
    {
        if(!visited[i]&& graph[s][i]==1)
    	printDFS( graph ,v, i ,visited,ans);
    }
    
}
void printDFS(int** graph ,int v,int s,bool* visited )
{
    vector<int >ans;
    printDFS( graph ,v, s,visited,ans);
    
    sort(ans.begin() , ans .end());
        
    for( auto i :ans )
        cout << i<<" ";
        
    
}
int main()
{
  int V, E;
  cin >> V >> E;

    int** graph = new int * [V];

    for(int i=0 ;i <V ;i++)
    {
        graph[i]=new int[V];
        for( int j=0 ;j<V ;j++)
            graph[i][j]=0; 
    }

    for(int i=0 ;i< E ;i++)
    {
        int x,y; 
        cin>>x>>y;
        graph[x][y]=1;
        graph[y][x]=1;
    }
    bool * visited=new bool[V];
    for(int i=0 ;i< V;i++)
        visited[V]= false;

    for(int i=0;i<V;i++)
    {
   		 if(!visited[i])
         { printDFS(graph,V , i,visited );
          cout<<endl;}
        
	}





    delete []  visited;
    for(int i = 0 ;i <V ;i++)
        delete [] graph[i];

    delete[] graph;


  return 0;
}
*/
void DFS(int** edges,int n , int s , int* visited, vector<int> &ans){
    ans.push_back(s);
    visited[s]=1;
    for(int i = 0 ; i < n ; i++){
        if(edges[s][i]==1 && visited[i]==0){
            ans.push_back(i);
            visited[i]=1;
        }
    }
}
void DFS(int** edges,int n , int s , int* visited){
    vector<int> ans;
    DFS(edges,n,s,visited,ans);
    sort(ans.begin(),ans.end);
    for(auto i:ans)
        cout<<i<<" ";
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,e;
    cin>>n>>e;
    int** edges = new int*[v]; 
    for(int i=0 ; i < v ; i++)
       edges[i] = new int[v];
        for(int i = 0 ; i < v ; i++){
            edges[i][j]=0;
        }
    for(int i = 0 ; i < e ; i++ ){
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }
    int* visited = new int*[v];
    for(int i = 0 ; i < v ; i++){
        visited[i]=0;
    }
        for(int i = 0 ; i < n ; i++ ){
            if(visited[i]==0){
                DFS(edges,v,i,visited);
            }
        }
        for(int i = 0 ; i < v ; i++){
            delete [] edges[i];
        }
    delete [] edges;
    delete [] visited;
        return 0;
}
