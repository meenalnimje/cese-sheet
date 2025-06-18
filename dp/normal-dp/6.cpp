#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> price(n);
    for (int i = 0; i < n; i++)
    {
        cin >> price[i];
    }
    vector<int> pages(n);
    for (int i = 0; i < n; i++)
    {
        cin >> pages[i];
    }
    // dp[i][j]=>maximum pages till index i having j cost
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= x; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j - price[i - 1] >= 0)
            {
                int a = pages[i - 1] + dp[i - 1][j - price[i - 1]];
                dp[i][j] = max(a, dp[i][j]);
            }
        }
    }
    cout << dp[n][x] << endl;

    return 0;
}