/*
Code : Kruskal's Algorithm
Send Feedback
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the Minimum Spanning Tree (MST) using Kruskal's algorithm.
For printing MST follow the steps -
1. In one line, print an edge which is part of MST in the format - 
v1 v2 w
where, v1 and v2 are the vertices of the edge which is included in MST and whose weight is w. And v1  <= v2 i.e. print the smaller vertex first while printing an edge.
2. Print V-1 edges in above format in different lines.
Note : Order of different edges doesn't matter.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)
Output Format :
Print the MST, as described in the task.
Constraints :
2 <= V, E <= 10^5
Time Limit: 1 sec
Sample Input 1 :
4 4
0 1 3
0 3 5
1 2 1
2 3 8
Sample Output 1 :
1 2 1
0 1 3
0 3 5
*/
#include <bits/stdc++.h>
using namespace std;
class Edges{
    public:
    int source;
    int det;
    int weight;
};
bool compare(Edges e1, Edges e2){  // this function return true or false on the basis of the comparison 
    return (e1.weight<e2.weight); 
}
int find_parent(int v1 ,int *parent){
    int pv1 = v1;
  while(parent[pv1]!=pv1){
		pv1=parent[pv1];
	}
	return pv1;
}
int main() {
    // Write your code here
    int v,e; // number of edges and vertices for the input for the graph
    cin>>v>>e;
    Edges input[e]; // is array mein har edge ka source destination or weight store hoga
    Edges output[v-1]; //to store the edges for the mst for the output and in mst there are n-1 edges
    for(int i = 0 ; i < e ; i++){ //input for the graph along with the weight of the edges source and destination
        int source,det,weight;
        cin>>source>>det>>weight;
        input[i].source=source;
        input[i].det=det;
        input[i].weight=weight;
    }
    int parent[v]; 
    for(int  i = 0 ; i < v ; i++){ // intially parent of evey vertex will be that vertex only
        parent[i]=i;
    }
    sort(input,input+e,compare);  // sorting the edges on the basis of the weights of the graph
    int count=0,i=0,v1,v2;  // to keep a count so that there should be only n-1 edges in the output array for the mst
    while(count<v-1){
         v1 = input[i].source;
         v2 = input[i].det;
         int pv1 = find_parent(v1,parent);
         int pv2 = find_parent(v2,parent);
        if(pv1!=pv2){   // parents of both the selected vertices v1 and v2 are differernt
            parent[pv1]=pv2;
            output[count].source = input[i].source;
            output[count].det = input[i].det;
            output[count].weight=input[i].weight;
            count=count+1;
        }
        i++;
    }
    for(int j = 0 ; j < v-1 ; j++ ){
        int minVertex=min(output[j].source,output[j].det);
		int maxVertex=max(output[j].source,output[j].det);
		cout<<minVertex<<" "<<maxVertex<<" "<<output[j].weight<<endl;
    }
    return 0;
}
