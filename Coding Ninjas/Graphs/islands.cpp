/**
 * Islands
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
 * 
*/

#include<iostream>
#include<vector>
using namespace std;

void dfs(int** edges,int n,int sv,bool* visited){
    visited[sv] = true;
    for(int i=0;i<n;i++){
        if(edges[sv][i] == 1 && visited[i] == false){
            dfs(edges,n,i,visited);
        }
    }
}

int solve(int n,int m,vector<int> u,vector<int> v)
{
	// Write your code here .
    // cout << "Inside solve" << endl;
    int** edges = new int*[n+1];
    for(int i=0;i<n+1;i++){
        edges[i] = new int[n+1];
        for(int j=0;j<n+1;j++){
            edges[i][j] = 0;
        }
    }
    // cout << "Matrix formed" << endl;
    for(int i=0;i<m;i++){
        edges[u[i]][v[i]] = 1;
        edges[v[i]][u[i]] = 1;
    }
    // cout << "Matrix filled" << endl;
    // for(int i=0;i<n+1;i++){
    //     for(int j=0;j<n+1;j++){
    //         cout << edges[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    bool* visited = new bool[n+1];
    for(int i=0;i<n+1;i++){
        visited[i] = false;
    }
    // cout << "Came till here " << endl;
    int count = 0;
    for(int i=1;i<n+1;i++){
        if(visited[i] == false){
            // cout << "NOt visited component" << endl;
            dfs(edges,n+1,i,visited);
            count++;
        }
    }
    return count;
}

