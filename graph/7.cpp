#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <climits>
// Dijsktra Algorithm
using namespace std;
using ll = long long;
int main()
{
    int n, m;
    cin >> n >> m;
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
    }
    vector<ll> ans(n + 1, LLONG_MAX);
    vector<int> visited(n + 1, 0);
    ans[1] = 0;

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, 1});
    while (!pq.empty())
    {
        pair<ll, ll> top = pq.top();
        pq.pop();
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
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}