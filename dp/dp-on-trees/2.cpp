// find the maximum sum of the subtree possible

// first find all the sum then take maximum and mini becz this doesnot only depend on dp[1] also summing and taking maximum was dificult

#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <climits>
using namespace std;
void dfs(int i, unordered_map<int, list<int>> &adjlist, vector<int> &visited, vector<int> &parents, vector<int> &sum, vector<int> &value)
{
    visited[i] = 1;
    for (auto it : adjlist[i])
    {
        if (!visited[it])
        {
            parents[it] = i;
            dfs(it, adjlist, visited, parents, sum, value);
        }
    }
    int tempsum = 0;
    for (auto it : adjlist[i])
    {
        if (it != parents[i])
        {
            tempsum += sum[it];
        }
    }
    sum[i] = value[i] + tempsum;
}
int main()
{
    int n;
    cin >> n;
    vector<int> value(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> value[i];
    }
    vector<vector<int>> edges(n - 1);
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        edges[i] = {x, y};
    }
    unordered_map<int, list<int>> adjlist;
    for (int i = 0; i < n - 1; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    vector<int> visited(n + 1, 0), parents(n + 1, 0), sum(n + 1, 0);
    dfs(1, adjlist, visited, parents, sum, value);
    int maxans = INT_MIN;
    for (int i = 1; i <= sum.size(); i++)
    {
        maxans = max(maxans, sum[i]);
    }
    cout << maxans << endl;
    return 0;
}
