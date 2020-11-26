#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
# define MOD 1000000007

int main(){
    int t;
    cin >> t;
    while(t--){
        ll k,d0,d1;
        cin >> k >> d0 >> d1;
        if((d0+d1)%3 == 0){
            cout << "YES" << endl;
        }
        else{
            cout <<  "NO" << endl;
        }
    }
    return 0;
}