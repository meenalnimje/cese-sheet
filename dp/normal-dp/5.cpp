#include <iostream>
#include <vector>
using namespace std;
const int mod = 1e9 + 7;
// https://cses.fi/problemset/task/1636
// order matter 5+2+2 is same as 2+5+2  unordered
int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, x;
    cin >> n >> x;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<long long> dp(x + 1, 0);
    dp[0] = 1;
    for (int coin : arr)
    {
        for (int i = coin; i <= x; ++i)
        {
            dp[i] = (dp[i] + dp[i - coin]) % mod;
        }
    }
    cout << dp[x] << endl;
    return 0;
}