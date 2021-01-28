/**
 * Code : All connected components
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

#include <iostream>
using namespace std;
#include<bits/stdc++.h>

void dfs(int** edges,int n,int sv,bool* visited,vector<int>& temp){
    temp.push_back(sv);
    visited[sv] = true;
    for(int i=0;i<n;i++){
        if(edges[sv][i] == 1 && visited[i] == false){
            dfs(edges,n,i,visited,temp);
        }
    }
}

int main()
{
  int V, E, tempX, tempY;
  cin >> V >> E;

  /*

  	   Write Your Code Here
	   Complete the Rest of the Program
	   You have to Print the output yourself
	 
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
    vector<int> temp;
    for(int i=0;i<V;i++){
        if(visited[i] == false){
            dfs(edges,V,i,visited,temp);
            sort(temp.begin(),temp.end());
            vector<int>::iterator it;
            for(it = temp.begin();it != temp.end();it++){
                cout << *it << " ";
            }
            cout << endl;
            temp.clear();
        }
    }

  return 0;
}
