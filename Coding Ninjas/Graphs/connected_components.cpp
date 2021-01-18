// #include<iostream>
// #include<vector>
// using namespace std;

// void dfs(int** edges,int n,int sv,bool* visited){
//     visited[sv] = true;
//     for(int i=0;i<n;i++){
//         if(edges[sv][i] == 1 && visited[i] == false){
//             dfs(edges,n,i,visited);
//         }
//     }
// }

// int solve(int n,int m,vector<int> u,vector<int> v)
// {
// 	// Write your code here .
//     // cout << "Inside solve" << endl;
//     int** edges = new int*[n+1];
//     for(int i=0;i<n+1;i++){
//         edges[i] = new int[n+1];
//         for(int j=0;j<n+1;j++){
//             edges[i][j] = 0;
//         }
//     }
//     // cout << "Matrix formed" << endl;
//     for(int i=0;i<m;i++){
//         edges[u[i]][v[i]] = 1;
//         edges[v[i]][u[i]] = 1;
//     }
//     // cout << "Matrix filled" << endl;
//     // for(int i=0;i<n+1;i++){
//     //     for(int j=0;j<n+1;j++){
//     //         cout << edges[i][j] << " ";
//     //     }
//     //     cout << endl;
//     // }
//     bool* visited = new bool[n+1];
//     for(int i=0;i<n+1;i++){
//         visited[i] = false;
//     }
//     // cout << "Came till here " << endl;
//     int count = 0;
//     for(int i=1;i<n+1;i++){
//         if(visited[i] == false){
//             // cout << "NOt visited component" << endl;
//             dfs(edges,n+1,i,visited);
//             count++;
//         }
//     }
//     return count;
// }


// int main()
// {
// 	int n,m;
// 	vector<int>u,v;
// 	cin>>n>>m;
// 	for(int i=0;i<m;i++)
// 	{
// 		int x;
// 		cin>>x;
// 		u.push_back(x);
// 	}
// 	for(int i=0;i<m;i++)
// 	{
// 		int x;
// 		cin>>x;
// 		v.push_back(x);
// 	}
// 	cout<<solve(n,m,u,v)<<endl;
// }
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

#include <iostream>
using namespace std;

void dfs(int** edges,int n,int sv,bool* visited){
    visited[sv] = true;
    for(int i=0;i<n;i++){
        if(edges[sv][i] == 1 && visited[i] == false){
            dfs(edges,n,i,visited);
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
    dfs(edges,V,0,visited);
    for(int i=0;i<V;i++){
        if(visited[i] == false){
            cout << "false" << endl;
            return 0;
        }
    }
	cout << "true" << endl;
  return 0;
}
