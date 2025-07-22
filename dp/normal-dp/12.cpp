#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
bool check(int i, vector<int> &arr, int idx, int sum, vector<vector<int>> &dp)
{
    if (idx >= arr.size())
    {
        if (sum == i)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    if (dp[idx][sum] != -1)
        return dp[idx][sum];
    int nottake = check(i, arr, idx + 1, sum, dp);
    int take = 0;
    if (sum + arr[idx] <= i)
    {
        int newsum = sum + arr[idx];
        take = check(i, arr, idx + 1, newsum, dp);
    }
    return dp[idx][sum] = take || nottake;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    int mini = INT_MAX;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
        mini = min(mini, arr[i]);
    }
    vector<int> ans;
    for (int i = mini; i <= sum; i++)
    {
        vector<vector<int>> dp(n + 1, vector<int>(i + 1, -1));
        if (check(i, arr, 0, 0, dp))
        {
            ans.push_back(i);
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (int i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}