#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <queue>
#include <list>
#include <climits>
using namespace std;
using ll = long long;
using pi = pair<ll, ll>;
// in this the dp[i][0]/ dp[i][1] will work as a distance array in actual dijkstra algo
int main()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> edges(m);
    for (int i = 0; i < m; i++)
    {
        ll x, y, z;
        cin >> x >> y >> z;
        edges[i] = {x, y, z};
    }
    unordered_map<ll, list<pi>> adjlist;

    for (int i = 0; i < m; i++)
    {
        ll u = edges[i][0];
        ll v = edges[i][1];
        ll w = edges[i][2];
        adjlist[u].push_back({v, w});
    }
    // dijkstra + dp
    vector<vector<ll>> dp(n + 1, vector<ll>(2, LLONG_MAX));

    // base case will be for 1
    dp[1][0] = 0;

    // we need to track wheather we have used the coupon or not till now in the path.
    // so priority_queue will be of form {price, {node, bool:coupon_used}}
    priority_queue<pair<ll, pi>, vector<pair<ll, pi>>, greater<pair<ll, pi>>> pq;
    // price,
    pq.push({0, {1, 0}});
    while (!pq.empty())
    {
        pair<ll, pi> top = pq.top();
        pq.pop();
        ll price = top.first;
        ll node = top.second.first;
        bool used = top.second.second;

        if (price > dp[node][used])
        {
            continue;
        }
        for (auto it : adjlist[node])
        {
            // coupon not used
            if (dp[it.first][used] > price + it.second)
            {
                dp[it.first][used] = price + it.second;
                ll newdistance = price + it.second;
                pq.push({newdistance, {it.first, used}});
            }
            if (used == 0 && dp[it.first][1] > price + (it.second / 2))
            {
                ll newdistance = price + (it.second / 2);
                dp[it.first][1] = newdistance;
                pq.push({dp[it.first][1], {it.first, 1}});
            }
        }
    }
    cout << min(dp[n][1], dp[n][0]) << endl;
    return 0;
}