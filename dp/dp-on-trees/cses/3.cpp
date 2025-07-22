// Diameter of a tree
#include <iostream>
#include <vector>
#include <list>
#include <climits>

#include <unordered_map>
using namespace std;
void dfs(int node, unordered_map<int, list<int>> &adjlist, vector<int> &dp, int parent)
{
    for (auto it : adjlist[node])
    {
        if (it != parent)
        {
            dfs(it, adjlist, dp, node);
        }
    }
    for (int it : adjlist[node])
    {
        dp[node] =max(dp[it],dp[node]);
    }
    if (dp[node] == INT_MIN)
    {
        dp[node] = 0;
        return;
    }
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> edges(n - 1);
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        edges[i] = {x, y};
    }
    unordered_map<int, list<int>> adjlist;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    // answer will be dp[1];
    vector<int> dp(n + 1, INT_MIN);
    dfs(1, adjlist, dp, -1);
    cout << dp[1] << endl;
    return 0;
}