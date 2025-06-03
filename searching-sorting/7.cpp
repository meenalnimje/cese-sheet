#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
// sum of two value
using ll = long long;
int main()
{
    ll n;
    cin >> n;
    long long k;
    cin >> k;
    vector<ll> arr(n);
    vector<pair<ll, int>> combine(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
        combine[i] = {arr[i], i};
    }
    sort(combine.begin(), combine.end());
    ll i = 0, j = n - 1;
    pair<ll, ll> ans = {LLONG_MAX, LLONG_MAX};
    while (i < j)
    {
        if ((ll)(combine[i].first + combine[j].first) == k)
        {
            ans = {combine[i].second, combine[j].second};
            break;
        }
        else if ((combine[i].first + combine[j].first) > k)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    if (ans.first == LLONG_MAX || ans.second == LLONG_MAX)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        cout << ans.first + 1 << " " << ans.second + 1 << endl;
    }

    return 0;
}