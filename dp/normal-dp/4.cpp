#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;
int solve(int num, vector<int> &dp)
{
    if (num == 0)
    {
        return 0;
    }
    if (dp[num] != -1)
        return dp[num];
    int ans = INT_MAX;
    // if we directly use num it will get altered
    int temp = num;
    while (temp > 0)
    {
        int last = temp % 10;
        if (last != 0)
        {
            ans = min(ans, 1 + solve(num - last, dp));
        }
        temp = temp / 10;
    }
    return dp[num] = ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    cout << solve(n, dp);

    return 0;
}