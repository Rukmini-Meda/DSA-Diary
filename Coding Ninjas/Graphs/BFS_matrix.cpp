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
