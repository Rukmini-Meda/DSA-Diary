#include<bits/stdc++.h>
using namespace std;

int minDPCostIterative(int cost[4][4],int n){
    int *dp = new int[1<<n];
    for(int i=0;i<(1<<n);i++){
        dp[i] = INT_MAX;
    }
    dp[0] = 0;
    for(int mask=0;mask<((1<<n)-1);mask++){
        int temp = mask;
        
    }
}

// Using DP, to solve the problem of repeated computation by overlapping problems
int minDPCost(int cost[4][4],int *dp,int n,int p,int mask){
    if(p>=n){
        return 0;
    }
    if(dp[mask]!=INT_MAX){
        return dp[mask];
    }
    int minimum = INT_MAX;
    for(int i=0;i<n;i++){
        if((mask&(1<<j)) == 0){
            int ans = minDPCost(cost,dp,n,p+1,mask|(1<<j))+cost[p][j];
            minimum = min(ans,minimum);
        }
    }
    dp[mask] = minimum;
    return dp[mask];
}

// Recursion & Bitmasking
int minCost(int cost[4][4],int n,int p,int mask){
    if(p>=n){
        return 0;
    }
    int minimum = INT_MAX;
    for(int j=0;j<n;j++){
        if((mask&(1<<j)) == 0){
            // For checking whether a bit is set
            // For setting a particular bit, use or
            int ans = minCost(cost,n,p+1,mask|(1<<j))+cost[p][j];
            minimum = min(ans,minimum);
            // cout << "ans is " << ans << endl;
            // cout << "min is " << minimum << endl;
        }
    }
    return minimum;
}

int main(){
    int cost[4][4] = {{10,2,6,5},{1,15,12,8},{7,8,9,3},{15,13,4,10}};
    cout << minCost(cost,4,0,0) << endl;
    int *dp = new int[1<<4];
    for(int i=0;i<(1<<4);i++){
        dp[i] = INT_MAX;
    }
    cout << minDPCost(cost,dp,4,0,0) << endl;
    return 0;
}