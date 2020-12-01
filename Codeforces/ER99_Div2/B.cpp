#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
# define MOD 1000000007

int main(){
    int t;
    cin >> t;
    while(t--){
        ll x;
        cin >> x;
        if((sqrt(1+(8*x))*sqrt(1+(8*x))) == (double)(1+(8*x))){
            cout << (sqrt(1+(8*x))-1)/2 << endl;
        }
        else{
            cout << x-1 << endl;
        }
    }
    return 0;
}