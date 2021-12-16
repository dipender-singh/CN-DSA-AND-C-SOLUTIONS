/*
Code : Get Path - DFS
Send Feedback
Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
Find the path using DFS and print the first path that you encountered.
Note:
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.
3. Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
4. Save the input graph in Adjacency Matrix.
Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two integers, that denote that there exists an edge between vertex 'a' and 'b'.
The following line contain two integers, that denote the value of v1 and v2.
Output Format :
Print the path from v1 to v2 in reverse order.
Constraints :
2 <= V <= 1000
1 <= E <= (V * (V - 1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1
0 <= v1 <= 2^31 - 1
0 <= v2 <= 2^31 - 1
Time Limit: 1 second
Sample Input 1 :
4 4
0 1
0 3
1 2
2 3
1 3
Sample Output 1 :
3 0 1
Sample Input 2 :
6 3
5 3
0 1
3 4
0 3
Sample Output 2 :
	*/
	#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
vector<int> *DFS(bool **edges,int n,int sv,int ev,bool *visited){
    if(sv==ev){
        vector<int> *v=new vector<int>();
        v->push_back(ev);
        return v;
    }
    visited[sv]=true;
    for(int i=0;i<n;i++){
        if(!visited[i] && edges[sv][i]){
            vector<int> *temp=DFS(edges,n,i,ev,visited);
            if(temp!=nullptr){
                temp->push_back(sv);
                return temp;
            }
        }
    }
    return nullptr;
}
int main(){
    int n,e;  //n->vertices,e->edges
    cin>>n>>e;
    bool **edges=new bool*[n];  //edges array(2D)
    for(int i=0;i<n;i++){
        edges[i]=new bool[n];
        for(int j=0;j<n;j++){
            edges[i][j]=false;
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
    int start,end;
    cin>>start>>end;
    vector<int> *ans=DFS(edges,n,start,end,visited);
    if(ans!=nullptr){
    for(int i=0;i<ans->size();i++){
        cout<<ans->at(i)<<" ";
    }
    }
    for(int i=0;i<n;i++){
        delete [] edges[i];
    }
    delete [] edges;
    delete[] visited;
}
