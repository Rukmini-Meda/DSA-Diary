#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
# define MOD 1000000007

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,c0,c1,h;
        cin >> n >> c0 >> c1 >> h;
        string s;
        cin >> s;
        int length = s.size();
        ll cost = 0;
        for(int i=0;i<length;i++){
            if(s[i] == '0'){
                cost += min(c0,h+c1);
            }
            else{
                cost += min(c1,h+c0);
            }
        }
        cout << cost << endl;
    }
    return 0;
}