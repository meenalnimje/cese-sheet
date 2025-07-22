#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
// bitmask dp:- when combination matters

int main()
{
    long long n, x;
    cin >> n >> x;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    long long totalpermutation = pow(2, n);
    vector<pair<long long, long long>> dp(totalpermutation, {n + 1, 0});
    dp[0] = {1, 0};
    for (int mask = 0; mask < totalpermutation; mask++)
    {
        for (int i = 0; i < n; i++)
        {
            if ((mask & (1 << i)) == 0)
            {
                // not included
                long long newmask = mask | (1 << i);
                pair<long long, long long> temp = dp[mask];
                long long ride = temp.first;
                long long weight = temp.second;
                if (weight + arr[i] <= x)
                {
                    dp[newmask] = min(dp[newmask], {ride, weight + arr[i]});
                }
                else
                {
                    dp[newmask] = min(dp[newmask], {ride + 1, arr[i]});
                }
            }
        }
    }
    cout << dp[totalpermutation - 1].first << endl;

    return 0;
}