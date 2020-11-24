#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        int arr[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> arr[i][j];
            }
        }
        bool visited[n][m] = {false};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j] == 1 && visited[i][j] == false){
                    visited[i][j] = true;
                    int k=j;
                    while(k<m && arr[i][k] != -1){
                        
                        if(arr[i][k] != 1){
                            visited[i][k] = true;
                        }
                        arr[i][k] = 1;
                        k++;
                    }
                    k = j;
                    while(k>=0 && arr[i][k] != -1){
                       if(arr[i][k] != 1){
                            visited[i][k] = true;
                        }
                        arr[i][k] = 1;
                        k--;
                    }
                    k=i;
                    while(k<n && arr[k][j] != -1){
                        if(arr[k][j] != 1){
                            visited[k][j] = true;
                        }
                        arr[k][j] = 1;
                        k++;
                    }
                    k=i;
                    while(k>=0 && arr[k][j] != -1){
                       if(arr[k][j] != 1){
                            visited[k][j] = true;
                        }
                        arr[k][j] = 1;
                        k--;
                    }
                    // for(int i=0;i<n;i++){
                    //     for(int j=0;j<m;j++){
                    //         // if(arr[i][j] == 1){
                    //         //     count++;
                    //         // }
                    //         cout << arr[i][j] << " ";
                    //     }
                    //     cout << endl;
                    // }
                    // cout << endl;
                    // cout << endl;
                }
            }
        }
        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j] == 1){
                    count++;
                }
                // cout << arr[i][j] << " ";
            }
            // cout << endl;
        }
        cout << count << endl;
    }
    return 0;
}