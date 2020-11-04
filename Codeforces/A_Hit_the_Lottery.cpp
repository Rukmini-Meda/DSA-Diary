#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[5] = {1,5,10,20,100};
    int c = 0;
    for(int i=4;i>=0 && n>0;i--){
        c += (n/arr[i]);
        n = n - (((n/arr[i]))*arr[i]);
        // cout << c << endl;
    }
    cout << c << endl;
    return 0;
}