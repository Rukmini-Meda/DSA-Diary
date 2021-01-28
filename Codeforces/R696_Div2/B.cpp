#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
# define MOD 1000000007

long long gcd(int a,int b){
    if(b == 0){
        return a;
    }
    return gcd(b,a%b);
}

long long lcm(int a,int b){
    return (a /gcd(a,b)) * b;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int d;
        cin >> d;
        cout << lcm(d+1,d+d+1) << endl;
    }
    return 0;
}