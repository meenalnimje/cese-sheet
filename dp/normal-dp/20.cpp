#include <iostream>
#include <vector>
using namespace std;
const int mod = 1e9 + 7;
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> dp(n, 0);
    dp[0] = 0;
    long long total = 0;
    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
            {
                dp[i] = (dp[i] + dp[j]) % mod;
            }
        }
        total = (total + dp[i]) % mod;
    }
    cout << total << endl;
    return 0;
}