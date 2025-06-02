#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
ll check(vector<ll> &hrr, ll target, vector<bool> &visited)
{
    ll ans = -1;
    ll low = 0;
    ll high = hrr.size() - 1;
    while (low <= high)
    {
        ll mid = (low + high) / 2;
        if (hrr[mid] <= target)
        {
                ans = mid;
                low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}
vector<ll> solve(vector<ll> &hrr, vector<ll> trr)
{
    vector<ll> ans;
    vector<bool> visited(hrr.size(), false);
    for (ll i = 0; i < trr.size(); i++)
    {
        ll temp = check(hrr, trr[i], visited);
        if (temp == -1)
        {
            ans.push_back(temp);
        }
        else
        {
            ans.push_back(hrr[temp]);
            hrr.erase(hrr.begin() + temp);
        }
    }
    return ans;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<ll> hrr(n), trr(m);
    for (ll i = 0; i < n; i++)
    {
        cin >> hrr[i];
    }
    for (ll i = 0; i < m; i++)
    {
        cin >> trr[i];
    }
    sort(hrr.begin(), hrr.end());
    vector<ll> resp = solve(hrr, trr);
    for (ll i : resp)
    {
        cout << i << endl;
    }
    return 0;
}