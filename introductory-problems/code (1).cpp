// ques 1 : weird algorithm

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <numeric>
#include <vector>
using namespace std;
unordered_map<int, vector<int>> dp;
vector<int> solve(int n)
{
    if (dp.find(n) != dp.end())
        return dp[n];
    vector<int> ans;
    ans.push_back(n);
    if (n == 1)
    {
        return dp[n] = ans;
    }
    vector<int> next;
    if (n % 2 == 0)
    {
        next = solve(n / 2);
    }
    else
    {
        next = solve((n * 3) + 1);
    }
    ans.insert(ans.end(), next.begin(), next.end());
    return dp[n] = ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> ans = solve(n);
    for (int i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
