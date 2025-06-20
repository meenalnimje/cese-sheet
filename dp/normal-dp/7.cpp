#include <iostream>
#include <vector>
using namespace std;
const int mod = 1e9 + 7;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<vector<int>> dp(n, vector<int>(m + 2, 0));
    if (arr[0] == 0)
    {
        for (int v = 1; v <= m; v++)
            dp[0][v] = 1;
    }
    else
    {
        dp[0][arr[0]] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (arr[i] == 0 || arr[i] == j)
            {
                dp[i][j] = ((long long)dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j + 1]) % mod;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= m; i++)
    {
        ans = (ans + dp[n - 1][i]) % mod;
    }

    cout << ans << endl;
    return 0;
}