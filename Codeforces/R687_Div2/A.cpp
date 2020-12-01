#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
# define MOD 1000000007

int main(){
    int t;
    cin >> t;
    while(t--){
        ll n,m,r,c;
        cin >> n >> m >> r >> c;
        cout << max(max(abs(r-1)+abs(c-1),abs(n-r)+abs(c-1)),max(abs(r-1)+abs(c-m),abs(n-r)+abs(m-c))) << endl;
    }
    return 0;
}