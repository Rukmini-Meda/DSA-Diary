/**
 * Code : BFS Traversal

Given an undirected and disconnected graph G(V, E), print its BFS traversal.
Note:
1. Here you need to consider that you need to print BFS path starting from vertex 0 only. 
2. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
3. E is the number of edges present in graph G.
4. Take graph input in the adjacency matrix.
5. Handle for Disconnected Graphs as well
Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains space separated two integers, that denote that there exists an edge between vertex a and b.
Output Format :
Print the BFS Traversal, as described in the task.
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
0 1 3 2
*/
#include <bits/stdc++.h>
using namespace std;

void print_bfs(int** edges,int n,int sv,bool* visited){
    queue<int> q;
    q.push(sv);
    visited[sv] = true;
    while(!q.empty()){
        int val = q.front();
        cout << val << " ";
        q.pop();
        for(int i=0;i<n;i++){
            if(edges[val][i] == 1 && visited[i] == false){
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int main() {
    int V, E;
    cin >> V >> E;

  /*

  	   Write Your Code Here
	   Complete the Rest of the Program
	   You have to take input and print the output yourself
	 
  */
    int** edges = new int*[V];
    for(int i=0;i<V;i++){
        edges[i] = new int[V];
        for(int j=0;j<V;j++){
            edges[i][j] = 0;
        }
    }
    for(int i=0;i<E;i++){
        int s,e;
        cin >> s >> e;
        edges[s][e] = 1;
        edges[e][s] = 1;
    }
    bool* visited = new bool[V];
    for(int i=0;i<V;i++){
        visited[i] = false;
    }
    for(int i=0;i<V;i++){
        if(visited[i] == false){
         	print_bfs(edges,V,i,visited);   
        }
    }
    delete [] visited;
    for(int i=0;i<V;i++){
        delete [] edges[i];
    }
    delete [] edges;
  return 0;
}
