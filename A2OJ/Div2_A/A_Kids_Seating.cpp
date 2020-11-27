#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        bool flags[(4*n)+1];
        for(int i=0;i<=(4*n);i++){
            flags[i] = true;
        }
        flags[0] = false;
        flags[1] = false;
        flags[2] = false;
        flags[3] = false;
        // for(int i=0;i<=4*n;i++){
        //     cout << flags[i] << " ";
        // }
        // cout << endl;
        int count = 0;
        vector<int> result;
        for(int i=0;i<=4*n && count<n;i++){
            // cout << "Why are you not working??" << endl;
            if(flags[i] == true && i%2 == 0){
                result.push_back(i);
                count++;
                // cout << "I am here" << endl;
                for(int j=i*2;j<=4*n;j+=i){
                    // cout << "I am in!!" << endl;
                    flags[j] = false;
                }
            }
        //     for(int k=0;k<=4*n;k++){
        //     cout << flags[k] << " ";
        // }
        // cout << endl;
        
        }
        // for(int i=0;i<=4*n;i++){
        //     cout << flags[i] << " ";
        // }
        // cout << endl;
        
        for(int i=0;i<n;i++){
            cout << result[i] << " ";
        }
        cout << endl;
    }
    return 0;
}