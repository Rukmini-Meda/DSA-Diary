#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
# define MOD 1000000007

int getConfigurationIndex(int rs,int re,int cs,int ce){
    if(rs == 0 && re == 0 && cs == 0 && ce == 0){
        return 0;
    }
    else if(rs == 1 && re == 1 && cs == 1 && ce == 1){
        return 1;
    }
    else if(rs == 1 && re == 1 && cs == 1 && ce == 0 ){
        return 2;
    }
    else if(rs == 1 && re == 0 && cs == 1 && ce == 1){
        return 3;
    }
    else if(rs == 0 && re == 1 && cs == 1 && ce == 1){
        return 4;
    }
    else if(rs == 1 && re == 1 && cs == 0 && ce == 1){
        return 5;
    }
    else if(rs == 1 && re == cs && cs == ce && re == 0){
        return 6;
    }
    else if(re == 1 && rs == cs && cs == ce && rs == 0){
        return 7;
    }
    else if(cs == 1 && re == rs && rs == ce && re == 0){
        return 8;
    }
    else if(ce == 1 && re == cs && cs == rs && re == 0){
        return 9;
    }
    else if(rs == re && rs == 1 && cs == ce && ce == 0){
        return 10;
    }
    else if(re == ce && re == 1 && rs == cs && cs == 0){
        return 11;
    }
    else if(cs == ce && ce == 1 && rs == re && re == 0){
        return 12;
    }
    else if(rs == cs && rs == 1 && re == ce && re == 0){
        return 13;
    }
    else if(rs == ce && rs == 1 && cs == re && re == 0){
        return 14;
    }
    else{
        return 15;
    }
}

void fill(int rs,int re,int cs,int ce, vector< pair<int,int> >& result){
    int index = getConfigurationIndex(rs,re,cs,ce);
    switch(index){
        case 0: break;
        case 1: result.push_back(make_pair(1,1));
                result.push_back(make_pair(1,2));
                result.push_back(make_pair(2,2));
        case 13: result.push_back(make_pair(1,1));
                result.push_back(make_pair(2,1));
                result.push_back(make_pair(1,2));
        case 7: result.push_back(make_pair(1,1));
                result.push_back(make_pair(1,2));
                result.push_back(make_pair(2,2));
                result.push_back(make_pair(1,1));
                result.push_back(make_pair(1,2));
                result.push_back(make_pair(2,1));
                result.push_back(make_pair(1,2));
                result.push_back(make_pair(2,1));
                result.push_back(make_pair(2,2));
                break;
        case 11: result.push_back(make_pair(1,1));
                result.push_back(make_pair(1,2));
                result.push_back(make_pair(2,1));
        case 8: result.push_back(make_pair(1,1));
                result.push_back(make_pair(1,2));
                result.push_back(make_pair(2,2));
                result.push_back(make_pair(1,1));
                result.push_back(make_pair(1,2));
                result.push_back(make_pair(2,1));
                result.push_back(make_pair(1,2));
                result.push_back(make_pair(2,1));
                result.push_back(make_pair(2,2));
                break;
        case 2: result.push_back(make_pair(1,1));
                result.push_back(make_pair(1,2));
                result.push_back(make_pair(2,1));
                break;
        case 3: result.push_back(make_pair(1,1));
                result.push_back(make_pair(2,1));
                result.push_back(make_pair(2,2));
                break;
        case 4: result.push_back(make_pair(1,2));
                result.push_back(make_pair(2,1));
                result.push_back(make_pair(2,2));
                break;
        case 5: result.push_back(make_pair(1,1));
                result.push_back(make_pair(1,2));
                result.push_back(make_pair(2,2));
                break;
        case 12: result.push_back(make_pair(1,1));
                result.push_back(make_pair(2,1));
                result.push_back(make_pair(2,2));
        case 6: result.push_back(make_pair(1,1));
                result.push_back(make_pair(1,2));
                result.push_back(make_pair(2,1));
                result.push_back(make_pair(1,1));
                result.push_back(make_pair(1,2));
                result.push_back(make_pair(2,2));
                result.push_back(make_pair(1,1));
                result.push_back(make_pair(2,1));
                result.push_back(make_pair(2,2));
                break;
        case 10: result.push_back(make_pair(1,1));
                result.push_back(make_pair(1,2));
                result.push_back(make_pair(2,2));
        case 9: result.push_back(make_pair(1,1));
                result.push_back(make_pair(1,2));
                result.push_back(make_pair(2,1));
                result.push_back(make_pair(1,1));
                result.push_back(make_pair(1,2));
                result.push_back(make_pair(2,2));
                result.push_back(make_pair(1,1));
                result.push_back(make_pair(2,1));
                result.push_back(make_pair(2,2));
                break;
        case 14: result.push_back(make_pair(1,1));
                 result.push_back(make_pair(1,2));
                 result.push_back(make_pair(2,1));
                 result.push_back(make_pair(1,2));
                 result.push_back(make_pair(2,1));
                 result.push_back(make_pair(2,2));
                break;
        case 15: result.push_back(make_pair(1,1));
                 result.push_back(make_pair(1,2));
                 result.push_back(make_pair(2,2));
                 result.push_back(make_pair(1,1));
                 result.push_back(make_pair(2,1));
                 result.push_back(make_pair(2,2));
                break;
        default: cout << "Something went wrong!";break;
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        int arr[n][m];
        for(int i=0;i<n;i++){
            string temp;
            cin >> temp;
            for(int j=0;j<m;j++){
                arr[i][j] = temp[j]-'0';
            }
        }
        vector<pair<int,int> > result;
        for(int i=0;i<n-1;i++){
            int sr = i, se = i+1, cr = 0, ce = 1;
            while(ce < m){
                fill(arr[sr][cr],arr[sr][ce],arr[se][cr],arr[se][ce],result);
                cr++;
                ce++;
            }
        }
        int length = result.size();
        cout << length/3 << endl;
        for(int i=0;i<length;i++){
            cout << result[i].first << " " << result[i].second << " ";
        }
        cout << endl;
    }
    return 0;
}