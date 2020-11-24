#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,x;
        cin >> n >> x;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        int b[n];
        for(int i=0;i<n;i++){
            cin >> b[i];
        }
        char blank;
        // cin >> blank;
        map<int,int> count;
        int flag = 0;
        for(int i=0;i<n;i++){
            if(count.find(b[i]) == count.end()){
                count[b[i]] = 1;
            }
            else{
                count[b[i]]++;
            }
        }
        map<int,int>::iterator it;
        for(it=count.begin();it!=count.end();it++){
            cout << it->first << " " << it->second << endl;
        }
        for(int i=0;i<n;i++){
            if(count.find(x-a[i]) == count.end() || count[a[i]] == 0){
                flag = 1;
                break;
            }
            else{
                count[x-a[i]]--;
            }
        }
        if(flag == 1){
            cout << "No" << endl;
        }
        else{
            cout << "Yes" << endl;
        }
    }
    return 0;
}