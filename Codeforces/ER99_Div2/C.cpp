#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
# define MOD 1000000007

int main(){
    int t;
    cin >> t;
    while(t--){
        ll x,y;
        cin >> x >> y;
        if(x == 1){
            cout << 0 << " " << y << endl;
        }
        else if(y == 1){
            cout << x-y << " " << 1 << endl;
        }
        else{
            cout << x << " " << y << endl;
        }
    }
    return 0;
}