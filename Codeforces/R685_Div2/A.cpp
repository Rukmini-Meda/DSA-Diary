#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
# define MOD 1000000007

int main(){
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        if(n == 1){
            cout << 0 << endl;
        }
        else if(n == 2){
            cout << 1 << endl;
        }
        else if(n%2 == 0 || n == 3){
            cout << 2 << endl;
        }
        else{
            cout << 3 << endl;
        }
    }
    return 0;
}