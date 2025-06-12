#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
ll solve(ll target, vector<ll> &arr)
{
    ll sum = 0;
    int i = 0;
    int n = arr.size();
    ll count = 0;
    for (int j = 0; j < n; j++)
    {
        sum += arr[j];
        while (sum > target)
        {
            sum -= arr[i];
            i++;
        }
        count += (j - i + 1);
    }
    return count;
}
int main()
{
    int n;
    cin >> n;
    ll x;
    cin >> x;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    ll temp1 = x - 1;
    ll temp2 = x;
    ll ans = solve(temp2, arr) - solve(temp1, arr);
    cout << ans << endl;
    return 0;
}