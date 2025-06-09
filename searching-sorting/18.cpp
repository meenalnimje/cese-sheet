#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<pair<ll, ll>> arr(n);
    map<pair<ll, ll>, ll> mapt;

    for (int i = 0; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        arr[i] = {x, y};
        mapt[{x, y}] = i;
    }

    vector<int> contains(n, 0);
    vector<int> contained_by(n, 0);

    // 1. Check "contains" -> sort by start descending, end ascending
    sort(arr.begin(), arr.end(), [](const pair<ll, ll> &a, const pair<ll, ll> &b) {
        if (a.first == b.first)
            return a.second < b.second;
        return a.first > b.first;
    });

    ll min_end = 2e9;
    for (int i = 0; i < n; i++)
    {
        ll start = arr[i].first;
        ll end = arr[i].second;
        pair<ll, ll> key = {start, end};
        int orig_idx = mapt[key];
        if (end >= min_end)
            contains[orig_idx] = 1;
        min_end = std::min(min_end, end);
    }

    // 2. Check "contained_by" -> sort by start ascending, end descending
    sort(arr.begin(), arr.end(), [](const pair<ll, ll> &a, const pair<ll, ll> &b) {
        if (a.first == b.first)
            return a.second > b.second;
        return a.first < b.first;
    });

    ll max_end = -1;
    for (int i = 0; i < n; i++)
    {
        ll start = arr[i].first;
        ll end = arr[i].second;
        pair<ll, ll> key = {start, end};
        int orig_idx = mapt[key];
        if (end <= max_end)
            contained_by[orig_idx] = 1;
        max_end = std::max(max_end, end);
    }

    for (int x : contains)
        cout << x << " ";
    cout << "\n";

    for (int x : contained_by)
        cout << x << " ";
    cout << "\n";

    return 0;
}
