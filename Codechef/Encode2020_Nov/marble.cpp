#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        if(n%2 == 0){
            cout << "B" << endl;
        }
        else{
            if(n == 1){
                cout << "B" << endl;
            }
            else{
                cout << "A" << endl;
            }
        }
    }
    return 0;
}