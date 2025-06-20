#include <iostream>
#include <vector>
using namespace std;
const int mod = 1e9 + 7;
int main()
{
    int n;
    cin >> n;
    vector<vector<char>> arr(n, vector<char>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    vector<vector<int>> dp(n, vector<int>(n, 0));
    if (arr[0][0] == '.')
        dp[0][0] = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i][0] == '.')
        {
            dp[i][0] = dp[i - 1][0];
        }
        else
        {
            break;
        }
    }
    for (int i = 1; i < n; i++)
    {
        if (arr[0][i] == '.')
        {
            dp[0][i] = dp[0][i - 1];
        }
        else
        {
            break;
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (arr[i][j] == '.')
            {
                dp[i][j] = ((long long)dp[i - 1][j] + dp[i][j - 1]) % mod;
            }
        }
    }
    cout << dp[n - 1][n - 1] << endl;

    return 0;
}