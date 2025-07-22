#include <iostream>
#include <vector>
using namespace std;
const int mod = 1e9 + 7;
int solve(int n, long long sum, int idx, vector<vector<int>> &dp)
{
    if (sum == 0)
        return 1;
    if (sum < 0)
        return 0;
    if (idx >= n)
    {
        if (sum == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    if (dp[idx][sum] != -1)
    {
        return dp[idx][sum];
    }
    int nottake = solve(n, sum, idx + 1, dp);
    int newsum = sum - idx;
    int take = solve(n, newsum, idx + 1, dp);
    return dp[idx][sum] = (take + nottake) % mod;
}
int main()
{
    int n;
    cin >> n;
    long long totalsum = (n * (n + 1)) / 2;
    if (totalsum % 2 != 0)
    {
        cout << 0 << endl;
    }
    else
    {
        vector<vector<int>> dp(n + 1, vector<int>((totalsum / 2) + 1, -1));
        int ans = solve(n, totalsum / 2, 1, dp);
        cout << ans << endl;
    }
    return 0;
}
