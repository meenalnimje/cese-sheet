#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <list>
using namespace std;
using ll = long long;
using pi = pair<ll, ll>;
int main()
{
    ll n, m, k;
    cin >> n >> m >> k;
    vector<vector<ll>> edges(m);
    for (int i = 0; i < m; i++)
    {
        int x, y, z;
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
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    vector<ll> count(n + 1, 0);
    vector<ll> ans;
    pq.push({0, 1});
    while (!pq.empty())
    {
        pi top = pq.top();
        pq.pop();
        ll price = top.first;
        ll node = top.second;
        count[node]++;
        if (node == n)
        {
            ans.push_back(price);
            if (int(ans.size()) == k)
            {
                break;
            }
        }
        if (count[node] > k)
        {
            continue;
        }
        for (auto it : adjlist[node])
        {
            ll nextprice = price + it.second;
            pq.push({nextprice, it.first});
        }
    }
    for (ll i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
