#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long max(long long a, long long b){
    if(a>b){
        return a;
    }
    return b;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<vector<long long>> dp(n + 1, vector<long long>(2, 0));
    dp[0][0] = 0;
    dp[0][1] = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        dp[i][1] = arr[i - 1] + max(dp[i - 1][0], dp[i-1][1]);
    }
    cout << max(dp[n][0], dp[n][1]) << endl;
    return 0;
}