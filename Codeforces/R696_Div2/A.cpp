#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
# define MOD 1000000007

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string p;
        cin >> p;
        string result = "1";
        int prev = 1 + (p[0] - '0');
        for(int i = 1; i < n; i ++){
            if(((p[i] - '0')+1) != prev){
                result += "1";
                prev = (p[i] - '0') + 1;
            }
            else{
                result += "0";
                prev = (p[i] - '0');
            }
        }
        cout << result << endl;
    }
    return 0;
}