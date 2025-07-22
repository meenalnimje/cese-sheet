#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;
// Prims algorithm for MST
// time complexity O(m log n)
using pi = pair<int, int>;
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
    unordered_map<int, list<pi>> adjlist;
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        adjlist[u].push_back({v, w});
        adjlist[v].push_back({u, w});
    }
    vector<int> visited(n + 1, 0);
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    // cost, node
    pq.push({0, 1});
    long long ans = 0;
    int count = 0;
    while (!pq.empty())
    {
        pi top = pq.top();
        pq.pop();
        if (visited[top.second])
        {
            continue;
        }
        count++;
        visited[top.second] = 1;
        ans += top.first;
        for (auto it : adjlist[top.second])
        {
            pq.push({it.second, it.first});
        }
    }
    if (count == n)
    {
        cout << ans << endl;
    }
    else
    {
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}
