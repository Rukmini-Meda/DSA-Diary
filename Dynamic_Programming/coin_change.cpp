#include<bits/stdc++.h>
using namespace std;

int coin_change_dp(int n,int *denom,int num,int **output){
    //NO amount
    if(n == 0){
        return 1;
    }
    //NO denominations
    if(num == 0 || n < 0){
        return 0;
    }
    if(output[n][num]>-1){
        return output[n][num];
    }
    int first = coin_change(n-denom[0],denom,num,output);
    int second = coin_change(n,denom+1,num-1,output);
    output[n][num] = first+second;
    return output[n][num];
}

int coin_change(int n,int *denom,int num){
    //NO amount
    if(n == 0){
        return 1;
    }
    //NO denominations
    if(num == 0 || n < 0){
        return 0;
    }
    int first = coin_change(n-denom[0],denom,num);
    int second = coin_change(n,denom+1,num-1);
    return first+second;
}

int main(){
    int d[2] = {1,2};
    int **output = new int*[value+1];
    for(int i=0;i<=value;i++){
        output[i] = new int[numDenominations+1];
    }
    for(int i=0;i<=value;i++){
        for(int j=0;j<=numDenominations;j++){
            output[i][j] = -1;
        }
    }
    cout << coin_change_dp(4,d,2,output) << endl;
    return 0;
}