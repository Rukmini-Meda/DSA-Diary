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
        map<int,int> indices;
        for(int i=0;i<n;i++){
            cin >> arr[i];
            indices[arr[i]] = i;
        }
        // int ans = -1;
        map<int,int> p;
        for(int i=0;i<n;i++){
            if(p.find(arr[i]) == p.end()){
                p[arr[i]] = 1;
            }
            else{
                p[arr[i]]++;
            }
        }
        map<int,int>::iterator it;
        bool flag = 0;
        for(it=p.begin();it!=p.end();it++){
            if(it->second == 1){
                cout << indices[it->first]+1 << endl;
                flag = 1;
                break;
            }
        }
        if(flag != 1){
            cout << -1 << endl;
        }
    }
    return 0;
}