#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// https://cses.fi/problemset/task/1631
using ll=long long;

bool ispossible(ll mid, vector<ll>&t, int n){
    ll count = 0;
    for(int i = 0; i < n; i++){
        count += (mid / t[i]);
    }
    return count >= n;
}

int solve(vector<ll>&t, int n){
    ll low = 1, high = 1e18;
    ll ans = -1;
    while(low <= high){
        ll mid = low + (high - low) / 2;
        if(ispossible(mid, t, n)){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<ll>t(n);
    for(int i = 0; i < n; i++){
        cin >> t[i];
    }
    cout << solve(t, n) << endl;

    return 0;
}
