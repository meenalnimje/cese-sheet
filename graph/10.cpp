#include <iostream>
#include <vector>
#include <list>
#include <climits>
#include <unordered_map>
using namespace std;
// dfs doesnot work for negative weights
//  we will use bellmad ford
int dfs(int start, int end, unordered_map<int, list<pair<int, int>>> &adjlist, vector<int> &visited)
{
    visited[start] = 1;
    if (start == end)
    {
        return 0;
    }
    int ans = INT_MIN;
    for (auto it : adjlist[start])
    {
        if (!visited[it.first])
        {
            ans = max(ans, it.second + dfs(it.first, end, adjlist, visited));
        }
    }
    return ans;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(m);
    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        edges[i] = {x, y, w};
    }
    unordered_map<int, list<pair<int, int>>> adjlist;
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        adjlist[u].push_back({v, w});
        adjlist[v].push_back({u, w});
    }
    int start = 1, end = n;
    vector<int> visited(n + 1, 0);
    int ans = dfs(start, end, adjlist, visited);
    cout << ans << endl;
    return 0;
}
