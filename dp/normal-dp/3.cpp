#include <iostream>
#include <vector>
using namespace std;
const int mod = 1e9 + 7;
// order does not matter 5+2+2 is different then 2+5+2
int main()
{
    // isme yeah niche wali ios wali line important thi.

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
    for (int i = 1; i <= x; i++)
    {
        for (int coins : arr)
        {
            if (i - coins >= 0)
            {
                dp[i] = (dp[i] + dp[i - coins]) % mod;
            }
        }
    }
    cout << dp[x] << endl;
    return 0;
}