#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int prev = INT_MIN;
    int count = 0, result = INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]>=prev){
            count++;
        }
        else{
            result = max(result,count);
            count = 1;
        }
        prev = arr[i];
    }
    result = max(count,result);
    cout << result << endl;
    return 0;
}