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


int main()
{
	int n,m;
	vector<int>u,v;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int x;
		cin>>x;
		u.push_back(x);
	}
	for(int i=0;i<m;i++)
	{
		int x;
		cin>>x;
		v.push_back(x);
	}
	cout<<solve(n,m,u,v)<<endl;
}