#include <iostream>
#include <vector>
#include <climits>
using namespace std;
using ll = long long;
ll max(ll a, ll b)
{
    if (a > b)
        return a;
    return b;
}
ll solve(int windowsize, vector<ll> &arr)
{
    int n = arr.size();
    ll sum = 0;
    for (int i = 0; i < windowsize; i++)
    {
        sum += arr[i];
    }
    ll ans = max(sum, LLONG_MIN);
    for (int i = windowsize; i < n; i++)
    {
        sum += (arr[i] - arr[i - windowsize]);
        ans = max(ans, sum);
    }
    return ans;
}
int main()
{
    ll n, a, b;
    cin >> n >> a >> b;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    ll ans = LLONG_MIN;
    for (int i = a; i <= b; i++)
    {
        ans = max(ans, solve(i, arr));
    }
    cout << ans << endl;

    return 0;
}