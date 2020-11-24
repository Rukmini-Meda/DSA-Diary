#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    int n,m;
    cin >> n >> m;
    int arr[m];
    for(int i=0;i<m;i++){
        cin >> arr[i];
    }
    int prev = 1;
    ll count = 0;
    for(int i=0;i<m;i++){
        if(arr[i]-prev >= 0){
            count += (arr[i] - prev);
            prev = arr[i];
        }
        else{
            count += (n+(arr[i]-prev));
            prev = arr[i];
        }
    }
    cout << count << endl;
    return 0;
}