#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <list>
using namespace std;
// for negative edges we use bellman ford for saftey
bool dfs(int node, set<int> &path, vector<int> &visited, unordered_map<int, list<pair<int, int>>> &adjlist, int count)
{
    visited[node] = 1;
    path.insert(node);
    for (auto it : adjlist[node])
    {
        if (visited[it.first] == 1 && dfs(it.first, path, visited, adjlist, count + it.second) && count < 0)
        {
            return true;
        }
    }
    visited[node] = 0;
    path.erase(node);
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(m);
    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        edges[i] = {x, y, z};
    }
    unordered_map<int, list<pair<int, int>>> adjlist;
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        adjlist[u].push_back({v, w});
    }
    set<int> ans;
    bool flag = false;
    for (int i = 1; i <= n; i++)
    {
        vector<int> visited(n + 1, 0);
        set<int> path;
        bool check = dfs(i, path, visited, adjlist, 0);
        if (check == true)
        {
            flag = true;
            ans = path;
            break;
        }
    }
    if (flag == true)
    {
        cout << "YES" << endl;
        while (!ans.empty())
        {
            int top = *ans.begin();
            cout << top << " ";
            ans.erase(top);
        }
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}