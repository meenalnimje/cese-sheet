#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
using namespace std;
// simple biaparty property

bool dfs(int i, vector<int> &visited, unordered_map<int, list<int>> &adjlist, int colour, vector<int> &groups)
{
    visited[i] = 1;
    groups[i] = colour;
    for (auto it : adjlist[i])
    {
        if (!visited[it])
        {
            if (!dfs(it, visited, adjlist, 3 - colour, groups))
            {
                return false;
            }
        }
        else if (groups[it] == groups[i])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        edges[i] = {x, y};
    }
    unordered_map<int, list<int>> adjlist;
    for (int i = 0; i < m; i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    bool flag = false; // false means we can divide
    vector<int> visited(n + 1, 0);
    vector<int> groups(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            int count = 1;
            if (!dfs(i, visited, adjlist, count, groups))
            {
                flag = true;
                break;
            }
        }
    }
    if (flag == false)
    {
        for (int i = 1; i <= groups.size()-1; i++)
        {
            cout << groups[i] << " ";
        }
    }
    else
    {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}