/**
 * Coding Ninjas
Send Feedback
Given a NxM matrix containing Uppercase English Alphabets only. Your task is to tell if there is a path in the given matrix which makes the sentence “CODINGNINJA” .
There is a path from any cell to all its neighbouring cells. For a particular cell, neighbouring cells are those cells that share an edge or a corner with the cell.
Input Format :
The first line of input contains two space separated integers N and M, where N is number of rows and M is the number of columns in the matrix. 
Each of the following N lines contain M characters. Please note that characters are not space separated.
Output Format :
Print 1 if there is a path which makes the sentence “CODINGNINJA” else print 0.
Constraints :
1 <= N <= 1000
1 <= M <= 1000
Time Limit: 1 second
Sample Input 1:
2 11
CXDXNXNXNXA
XOXIXGXIXJX
Sample Output 1:
1
*/

bool dfs(char graph[][MAXN],int n,int m,string title,int index,int si,int sj,bool** visited){
    // cout << si << " " << sj << endl;
    visited[si][sj] = true;
    if(index == 10){
        return true;
    }
    if(sj+1<m && graph[si][sj+1] == title[index+1] && visited[si][sj+1] == false){
        if(dfs(graph,n,m,title,index+1,si,sj+1,visited)){
            return true;
        }
    }
    if(si-1>=0 && sj+1<m && graph[si-1][sj+1] == title[index+1] && visited[si-1][sj+1] == false){
        if(dfs(graph,n,m,title,index+1,si-1,sj+1,visited)){
            return true;
        }
    }
    if(si-1>=0 && graph[si-1][sj] == title[index+1] && visited[si-1][sj] == false){
        if(dfs(graph,n,m,title,index+1,si-1,sj,visited)){
            return true;
        }
    }
    if(si-1>=0 && sj-1>=0 && graph[si-1][sj-1] == title[index+1] && visited[si-1][sj-1] == false){
        if(dfs(graph,n,m,title,index+1,si-1,sj-1,visited)){
            return true;
        }
    }
    if(sj-1>=0 && graph[si][sj-1] == title[index+1] && visited[si][sj-1] == false){
        if(dfs(graph,n,m,title,index+1,si,sj-1,visited)){
            return true;
        }
    }
    if(si+1<n && sj-1>=0 && graph[si+1][sj-1] == title[index+1] && visited[si+1][sj-1] == false){
        if(dfs(graph,n,m,title,index+1,si+1,sj-1,visited)){
            return true;
        }
    }
    if(si+1<n && graph[si+1][sj] == title[index+1] && visited[si+1][sj] == false){
        if(dfs(graph,n,m,title,index+1,si+1,sj,visited)){
            return true;
        }
    }
    if(si+1<n && sj+1<m && graph[si+1][sj+1] == title[index+1] && visited[si+1][sj+1] == false){
        if(dfs(graph,n,m,title,index+1,si+1,sj+1,visited)){
            return true;
        }
    }
    // cout << "Returning false at " << si <<" "<< sj << endl;
    visited[si][sj] = false;
    return false;
    
}


int solve(char Graph[][MAXN],int N, int M)
{
	// Write your code here.
    
    bool** visited = new bool*[N];
    for(int i=0;i<N;i++){
        visited[i] = new bool[M];
        for(int j=0;j<M;j++){
            visited[i][j] = false;
        }
    }
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(Graph[i][j] == 'C'){
                if(dfs(Graph,N,M,"CODINGNINJA",0,i,j,visited)){
                    return 1;
                }
            }
        }
    }
    
    return 0;
    
}