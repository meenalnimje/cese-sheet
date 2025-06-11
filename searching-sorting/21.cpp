#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
using ll = long long;
bool check(vector<ll> &arr, ll t, ll mid)
{
    ll count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        count += mid / arr[i];
        if (count >= t)
            return true;
    }
    return count >= t;
}
ll solve(vector<ll> &arr, ll t, ll n)
{
    if (arr.size() == 1)
    {
        return t * arr[0];
    }
    ll ans = -1;
    ll low = 0, high = 1e18;
    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        if (check(arr, t, mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}
int main()
{
    ll n, t;
    cin >> n >> t;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << solve(arr, t, n) << endl;

    return 0;
}