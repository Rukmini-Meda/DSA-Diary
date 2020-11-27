#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
# define MOD 1000000007

void fillPrime(vector< pair<ll,ll> >& numPrimeFactors, ll n){
    pair<ll,ll> two;
    two.first = 2;
    two.second = 0;
    while(n%2 == 0){
        // cout << 2 << " ";
        two.second++;
        n /= 2;
    }
    if(two.second>0){
        numPrimeFactors.push_back(two);
    }
    // cout << "hh" << endl;
    for(ll i=3;i*i<=n;i+=2){
        pair<ll,ll> pa;
        pa.first = i;
        pa.second = 0;
        while(n%i == 0){
            // cout << i << " ";
            pa.second++;
            n /= i;
        }
        if(pa.second>0){
            numPrimeFactors.push_back(pa);
        }
    }
    // cout << "ll" << endl;
    if(n>2){
        // cout << n << " ";
        numPrimeFactors.push_back(make_pair(n,1));
    }
    // cout << endl;
}

bool cmp(pair<ll,ll>& p1,pair<ll,ll>& p2){
    return p1.second >= p2.second;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector< pair<ll,ll> > numPrimeFactors;
        fillPrime(numPrimeFactors,n);
        sort(numPrimeFactors.begin(),numPrimeFactors.end(),cmp);
        ll k = numPrimeFactors[0].second;
        vector<ll> result(k,(ll)1); 
        ll m = numPrimeFactors.size();
        ll l=0;
        for(int i=0;i<m;i++){
            ll j = k-1, o=0;
            while(j>=0 && o<numPrimeFactors[i].second){
                result[j] *= numPrimeFactors[i].first;
                j--;
                o++;
            }
        }
        cout << k << endl;
        for(int i=0;i<k;i++){
            cout << result[i] << " ";
        }
        cout << endl;
    }
    return 0;
}