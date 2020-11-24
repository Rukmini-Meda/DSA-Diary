#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll numberOfSetBits(ll val){
    ll count = 0;
    while(val > 0){
        if(val & 1 == 1){
            count++;
        }
        val >>= 1;
    }
    return count;
}

int main(){
    int n,m,k;
    cin >> n >> m >> k;
    ll arr[m+1];
    for(int i=0;i<m+1;i++){
        cin >> arr[i];
    }
    int count = 0;
    for(int i=0;i<m;i++){
        ll val = arr[i]^arr[m];
        ll num = numberOfSetBits(val);
        if(num <= k){
            count++;
        }
    }
    cout << count << endl;
    return 0;
}