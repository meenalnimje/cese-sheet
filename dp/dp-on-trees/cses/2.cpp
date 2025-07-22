// Diameter of a tree
#include <iostream>
#include <vector>
#include <list>
#include <climits>

#include <unordered_map>
using namespace std;
void dfs(int node, unordered_map<int, list<int>> &adjlist, vector<vector<int>> &dp, int parent)
{
    for (auto it : adjlist[node])
    {
        if (it != parent)
        {
            dfs(it, adjlist, dp, node);
        }
    }
    int without_node = 0;
    for (int it : adjlist[node])
    {
        if (it != parent)
        {
            without_node += max(dp[it][0], dp[it][1]);
        }
    }
    dp[node][0] = without_node;
    int withnode = 0;
    for (int it : adjlist[node])
    {
        if (it != parent)
        {
            // child will be 0 and child ka child without_node-max() wala part hai
            withnode = max(withnode, 1 + dp[it][0] + without_node - max(dp[it][0], dp[it][1]));
        }
    }
    dp[node][1] = withnode;
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
    vector<vector<int>> dp(n + 1, vector<int>(2, INT_MIN));
    dfs(1, adjlist, dp, -1);
    cout << max(dp[1][0], dp[1][1]) << endl;
    return 0;
}