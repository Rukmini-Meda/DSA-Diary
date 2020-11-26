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
        int arr[n];
        for(int i=0;i<n;i++){
            cin >> arr[i];
        }
        map<int,int> p,c;
        int ans = INT_MAX;
        for(int i=0;i<n;i++){
            if(p.find(arr[i]) == p.end()){
                p[arr[i]] = i;
                if(i == 0){
                    c[arr[i]] = 0;
                }
                else{
                    c[arr[i]] = 1;
                }
            }
            else{
                if((i-p[arr[i]])>1){
                    c[arr[i]]++;
                }
                p[arr[i]] = i;
            }
        }
        map<int,int>::iterator it;
        for(it=p.begin();it!=p.end();it++){
            if(it->second != n-1){
                c[it->first]++;
            }
        }
        for(it=c.begin();it!=c.end();it++){
            ans = min(ans,it->second);
        }
        cout << ans << endl;
    }
    return 0;
}