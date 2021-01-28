/**
 * Code : Has Path

Given an undirected graph G(V, E) and two vertices v1 and v2 (as integers), check if there exists any path between them or not. Print true if the path exists and false otherwise.
Note:
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.
Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two integers, that denote that there exists an edge between vertex 'a' and 'b'.
The following line contain two integers, that denote the value of v1 and v2.
Output Format :
The first and only line of output contains true, if there is a path between v1 and v2 and false otherwise.
Constraints :
0 <= V <= 1000
0 <= E <= 1000
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
true
Sample Input 2 :
6 3
5 3
0 1
3 4
0 3
Sample Output 2 :
false

*/

/*
Time complexity - O(V+E)
Space complexity - O(V^2)

where V is the number of vertices in the input graph and E is the number of edges
in the input graph
*/

#include<bits/stdc++.h>
using namespace std;

bool hasPathHelper(bool **graph, int v, int start, int end, bool *visited){
    if(start == end){
        return true;
    }
    visited[start] = true;
    for(int i=0;i<v;i++){
        if(graph[start][i] && !visited[i]){
            if(hasPathHelper(graph, v, i, end, visited)){
                return true;
            }
        }
    }
    return false;
}

bool hasPath(bool **graph, int v, int start, int end){
    bool *visited = new bool[v]();
    return hasPathHelper(graph, v, start, end, visited);
    delete [] visited;
}

int main(){
    int v, e;
    cin >> v >> e;
    bool **graph = new bool*[v];
    for(int i=0;i<v;i++){
        graph[i] = new bool[v]();
    }
    for(int i=0,a,b;i<e;i++){
        cin >> a >> b;
        graph[a][b] = true;
        graph[b][a] = true;
    }
    int start, end;
    cin >> start >> end;
    cout << (hasPath(graph, v, start, end)?"true":"false");
    for(int i=0;i<v;i++){
        delete [] graph[i];
    }
    delete [] graph;
}