#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
using namespace std;
void dfs(int node, unordered_map<int, list<int>> &adjlist, int parent, vector<int> &dp)
{
    for (int it : adjlist[node])
    {
        if (it != parent)
        {
            dfs(it, adjlist, node, dp);
        }
    }
    if (adjlist[node].size() == 0)
    {
        dp[node] = 0;
        return;
    }
    else
    {
        for (int it : adjlist[node])
        {
            dp[node] = dp[node] + dp[it] + 1;
        }
        return;
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n - 1);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> arr[i];
    }
    unordered_map<int, list<int>> adjlist;
    for (int i = 0; i < arr.size(); i++)
    {
        // adjlist[i+2].push_back(arr[i]);
        adjlist[arr[i]].push_back(i + 2);
    }
    // for (auto it = adjlist.begin(); it != adjlist.end(); it++)
    // {
    //     cout << it->first << " -> ";
    //     for (auto j : adjlist[it->first])
    //     {
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }
    vector<int> dp(n + 1, 0);
    dfs(1, adjlist, -1, dp);
    for (int i = 1; i < dp.size(); i++)
    {
        cout << dp[i] << " ";
    }

    return 0;
}