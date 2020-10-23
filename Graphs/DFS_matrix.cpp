#include<bits/stdc++.h>
using namespace std;

void print(int **arr,int n,int sv,bool *visited){
    cout << sv << " ";
    visited[sv] = true;
    for(int i=0;i<n;i++){
        if(arr[sv][i] == 1 && visited[i] == false){
            print(arr,n,i,visited);
        }
    }
}

int main(){
    int m,n;
    cin >> n >> m;
    int** arr = new int*[n];
    for(int i=0;i<n;i++){
        arr[i] = new int[n];
        for(int j=0;j<n;j++){
            arr[i][j] = 0;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    for(int i=0;i<m;i++){
        int s,e;
        cin >> s >> e;
        arr[s][e] = 1;
        arr[e][s] = 1;
    }
    bool *visited = new bool[n];
    for(int i=0;i<n;i++){
        visited[i] = false;
    }
    print(arr,n,0,visited);
    delete [] visited;
    for(int i=0;i<n;i++){
        delete [] arr[i];
    }
    delete [] arr;
    return 0;
}