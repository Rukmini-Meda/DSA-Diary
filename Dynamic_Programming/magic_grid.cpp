#include<bits/stdc++.h>
using namespace std;

//Wrong code ... correct it from codezen
int magic_grid(int arr[][1000],int r,int c){
    int **dp = new int*[r+1];
    for(int i=0;i<=r;i++){
        dp[i] = new int[c+1];
    }
    dp[r-1][c-1] = arr[r-1][c-1];
    for(int i=0;i<r;i++){
        dp[i][c-1] = dp[i][c-2] + arr[i][c-1];
    }
    for(int i=0;i<c;i++){
        dp[r-1][i] = dp[r-2][i] + arr[r-1][i];
    }
    for(int i=r-2;i>=0;i--){
        for(int j=c-2;j>=0;j--){
            dp[i][j] = min(dp[i][j+1],dp[i+1][j]);
        }
    }
    int ans = dp[0][0];
    delete [] dp;
    return ans;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int r,c;
        cin >> r >> c;
        int arr[r][c];
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cin >> arr[i][j];
            }
        }
        
        cout << magic_grid(arr,r,c) << endl;
    }
    return 0;
}