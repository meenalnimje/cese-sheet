#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;
const int mod = 1e9 + 7;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(m);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        edges[i] = {x, y};
    }
    vector<int> indegree(n + 1, 0);
    unordered_map<int, list<int>> adjlist;
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adjlist[u].push_back(v);
        indegree[v]++;
    }
    queue<int> q;
    for (int i = 0; i < indegree.size(); i++)
    {
        if (i != 0 && indegree[i] == 0)
        {
            q.push(i);
        }
    }
    vector<int>temp;
    int count = 0;
    while (!q.empty())
    {
        int top = q.front();
        q.pop();
        temp.push_back(top);
        for (auto it : adjlist[top])
        {
            indegree[it]--;
            if (indegree[it] == 0)
            {
                q.push(it);
            }
        }
    }
    vector<int>dp(n+1,0);
    // dp[i]=no. of ways to reach from 1 to i
    dp[1]=1;
    for (int u : temp) {
        for (int v : adjlist[u]) {
            // v=>child take pohochne ke kite tarike honge woh u jitne hi hinge
            
            dp[v] = (dp[v] + dp[u]) % mod;
        }
    }

    cout << dp[n] << endl;

    return 0;
}