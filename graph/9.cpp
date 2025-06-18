#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <climits>

// instead of  Dijsktra Algorithm use 
//  Floyd-Warshall Algorithm (when n ≤ 500)
// Time Complexity: O(n³)
// Works well when n is small (≤ 500), which is typical for such query-based all-pairs shortest path problems.

using namespace std;
using ll = long long;
ll bfs(unordered_map<ll, list<pair<ll, ll>>> &adjlist, int n, int start, int end)
{
    vector<ll> ans(n + 1, LLONG_MAX);
    vector<int> visited(n + 1, 0);
    ans[1] = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, start});
    while (!pq.empty())
    {
        pair<ll, ll> top = pq.top();
        pq.pop();
        if (top.second == end)
        {
            return top.first;
        }
        if (visited[top.second])
            continue;
        visited[top.second] = 1;
        for (auto it : adjlist[top.second])
        {
            if (!visited[it.first] && top.first + it.second < ans[it.first])
            {
                ans[it.first] = top.first + it.second;
                pq.push({ans[it.first], it.first});
            }
        }
    }
    return -1;
}
int main()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<long long>> edges(m);
    for (int i = 0; i < m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        edges[i] = {u, v, w};
    }
    // make adjlist

    unordered_map<ll, list<pair<ll, ll>>> adjlist;
    for (int i = 0; i < m; i++)
    {
        ll u = edges[i][0];
        ll v = edges[i][1];
        ll w = edges[i][2];
        adjlist[u].push_back({v, w});
        adjlist[v].push_back({u, w});
    }

    vector<vector<int>> query(q);
    for (int i = 0; i < q; i++)
    {
        int x, y;
        cin >> x >> y;
        vector<int> temp = {x, y};
        sort(temp.begin(), temp.end());
        query[i] = temp;
    }

    for (int i = 0; i < q; i++)
    {
        int start = query[i][0];
        int end = query[i][1];
        ll ans = bfs(adjlist, n, start, end);
        cout << ans << endl;
    }

    return 0;
}