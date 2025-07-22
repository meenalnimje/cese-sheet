#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
// Digit dp question
long long dp[20][10][2][2];
// pos,prev-digit,limit,leading-zero
long long solve(int pos, int prev_digit, bool tight, bool leading_zero, string &st)
{
    if (pos == st.size())
    {
        return 1;
    }
    if (dp[pos][prev_digit][tight][leading_zero] != -1)
    {
        return dp[pos][prev_digit][tight][leading_zero];
    }
    int limit = tight ? st[pos] - '0' : 9;
    long long res = 0;
    for (int dig = 0; dig <= limit; ++dig)
    {
        if (!leading_zero && dig == prev_digit)
            continue;

        res += solve(
            pos + 1,
            dig,
            tight && (dig == limit),
            leading_zero && (dig == 0), st);
    }
    return dp[pos][prev_digit][tight][leading_zero] = res;
}

long long count(long long num)
{
    string st = to_string(num);
    memset(dp, -1, sizeof(dp));
    return solve(0, 0, 1, 1, st);
}
int main()
{
    long long a, b;
    cin >> a >> b;
    long long ans1 = count(b);
    long long ans2 = count(a - 1);
    cout << ans1 - ans2 << endl;
    return 0;
}