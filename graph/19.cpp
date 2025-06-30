#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

const int MOD = 1e9 + 7;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1); // adj[u] = {v, weight}
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    vector<long long> dist(n + 1, LLONG_MAX);
    vector<int> ways(n + 1, 0);
    vector<int> minFlights(n + 1, INT_MAX);
    vector<int> maxFlights(n + 1, 0);

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    pq.push({0, 1}); // cost, node

    dist[1] = 0;
    ways[1] = 1;
    minFlights[1] = 0;

    while (!pq.empty())
    {
        auto [cost, u] = pq.top();
        pq.pop();

        if (cost > dist[u])
            continue;

        for (auto [v, w] : adj[u])
        {
            long long newCost = cost + w;
            if (newCost < dist[v])
            {
                dist[v] = newCost;
                ways[v] = ways[u];
                minFlights[v] = minFlights[u] + 1;
                maxFlights[v] = maxFlights[u] + 1;
                pq.push({newCost, v});
            }
            else if (newCost == dist[v])
            {
                ways[v] = (ways[v] + ways[u]) % MOD;
                minFlights[v] = min(minFlights[v], minFlights[u] + 1);
                maxFlights[v] = max(maxFlights[v], maxFlights[u] + 1);
            }
        }
    }

    cout << dist[n] << " " << ways[n] << " " << minFlights[n] << " " << maxFlights[n] << endl;
    return 0;
}
