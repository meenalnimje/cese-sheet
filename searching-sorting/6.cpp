#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
using ll = long long;
// maximum number of non overlapping intervals
bool static comp(pair<ll, ll> &a, pair<ll, ll> &b)
{
    return a.second < b.second;
}
int main()
{
    int n;
    cin >> n;
    vector<pair<ll, ll>> arr(n);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        arr[i] = {x, y};
    }
    sort(arr.begin(), arr.end(), comp);
    ll ending = LLONG_MIN;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].first >= ending)
        {
            count++;
            ending = arr[i].second;
        }
    }
    cout << count << endl;
    return 0;
}