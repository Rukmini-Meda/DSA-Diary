#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll nc2(ll n){
    return (n*(n-1))/2;
}

int main(){
    ll n,m;
    cin >> n >> m;
    ll maxi = nc2(n-m+1);
    ll r = n%m,g = n/m;
    ll mini = ((r*(nc2(1+g)))+((m-r)*(nc2(g))));
    cout << mini << " " << maxi << endl;
    return 0;
}