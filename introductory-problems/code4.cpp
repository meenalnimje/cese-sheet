#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

bool ispossible(vector<ll>& arr, vector<ll>& brr, ll mid) {
    ll n = arr.size();
    ll used = 0;
    ll i = 0, j = 0;

    while (i<n && j < brr.size()) {
        if (i < n && arr[i] >= brr[j]) {
            i++;
            j++;
        } else if (!used && mid >= brr[j]) {
            used = 1;
            j++;  
        } else {
            i++;
        }
    }

    return j == brr.size();
}

ll solve(vector<ll>& arr, vector<ll>& brr) {
    sort(arr.begin(), arr.end());
    sort(brr.begin(), brr.end());

    if (ispossible(arr, brr, 0)) return 0;

    ll low = 1, high = 1e9 + 1, ans = -1;
    while (low <= high) {
        ll mid = low+(high - low) / 2;
        if (ispossible(arr, brr, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    cout<<"start"<<endl;
    int t;
    cin >> t;
    while (t--) {
        ll n, m;
        cin >> n >> m;
        vector<ll> arr(n), brr(m);
        for (ll i = 0; i < n; i++){
            cin >> arr[i];
        } 
        for (ll i = 0; i < m; i++){ 
            cin >> brr[i];
        }
        cout << solve(arr, brr) << endl;
    }
    return 0;
}

