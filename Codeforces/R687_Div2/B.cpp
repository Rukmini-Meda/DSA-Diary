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
        int arr[n];
        for(int i=0;i<n;i++){
            cin >> arr[i];
        }
        int p=0,i=1;
        vector<int> count,col;
        for(;i<n;i++){
            if(arr[i] != arr[p]){
                count.push_back(i-p);
                col.push_back(arr[p]);
                p = i;
            }
        }
        count.push_back(i-p);
        col.push_back(arr[p]);
        int length = count.size();
        int color,maxx = INT_MIN;
        for(int i=0;i<length;i++){
            if(count[i] > maxx){
                maxx = count[i];
                color = col[i];
            }
            // cout << count[i] << " " << col[i] << endl;
        }
        ll ans = 0;
        for(int i=0;i<n;i++){
            int count2 = 0;
            while(i<n && arr[i] != color){
                count2++;
                i++;
            }
            if(count2>0){
                // cout << count2 << endl;
                // cout << ceil((double)count2/k) << endl;
                ans += (ceil((double)count2/k));
            }
        }
        cout << ans << endl;
    }
    return 0;
}