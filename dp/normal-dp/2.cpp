#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> dp(x + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= x; i++)
    {
        for (int coin : arr)
        {
            if (i - coin >= 0 && dp[i - coin] != INT_MAX)
            {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }
    if (dp[x] == INT_MAX)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << dp[x] << endl;
    }
    return 0;
}