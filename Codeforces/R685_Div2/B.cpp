#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
# define MOD 1000000007

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,q;
        cin >> n >> q;
        string s;
        cin >> s;
        while(q--){
            int l,r;
            cin >> l >> r;
            char start = s[l-1];
            char end = s[r-1];
            int i=l-2,j=r;
            bool flag = false;
            while(i>=0){
                if(s[i] == start){
                    flag = true;
                    break;
                }
                i--;
            }
            while(j<n){
                if(s[j] == end){
                    flag = true;
                    break;
                }
                j++;
            }
            if(flag == true){
                cout << "yes" << endl;
            }
            else{
                cout << "no" << endl;
            }
        }
    }
    return 0;
}