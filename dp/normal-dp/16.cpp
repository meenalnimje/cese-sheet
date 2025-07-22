#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
static bool comp(vector<int> &a, vector<int> &b)
{
    return a[1] < b[1];
}
int findLastNonOverlapping(vector<vector<int>> &arr, int idx)
{
    int low = 0, high = idx - 1;
    int ans = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid][1] < arr[idx][0])
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> arr(n);
    for (int i = 0; i < n; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        arr[i] = {x, y, z};
    }
    // sort based on starting poin
    sort(arr.begin(), arr.end(), comp);
    vector<long long> dp(n);
    dp[0] = arr[0][2];
    for (int i = 1; i < n; i++)
    {
        int prev = findLastNonOverlapping(arr, i);
        long long newreward = arr[i][2];
        if (prev != -1)
        {
            newreward += dp[prev];
        }
        dp[i] = max(newreward, dp[i - 1]);
    }
    cout << dp[n - 1] << endl;
    return 0;
}