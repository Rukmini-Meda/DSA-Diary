#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
# define MOD 1000000007

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        int m = n*k;
        ll arr[m];
        for(int i=0;i<m;i++){
            cin >> arr[i];
        }
        reverse(arr,arr+m);
        int mid = ceil(n/2.0);
        int window = n-mid+1;
        int i=0,j=window;
        ll sum = 0;
        while(i<k){
            sum += arr[j-1];
            j+=window;
            i++;
        }
        cout << sum << endl;
    }
    return 0;
}