#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
using namespace std;
void dfs(int node, int parent, vector<int> &path, vector<vector<int>> &totalpath, unordered_map<int, list<int>> &adjlist, int n)
{
    path.push_back(node);
    if (node == n)
    {
        totalpath.push_back(path);
        path.pop_back(); // pop after getting the node
        return;
    }
    for (auto it : adjlist[node])
    {
        if (it != parent)
        {
            dfs(it, node, path, totalpath, adjlist, n);
        }
    }
    path.pop_back();
}
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
    unordered_map<int, list<int>> adjlist;
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adjlist[u].push_back(v);
    }
    vector<int> path;
    vector<vector<int>> totalpath;
    dfs(1, -1, path, totalpath, adjlist, n);
    int maxsize = 0;
    vector<int> ans;
    for (int i = 0; i < totalpath.size(); i++)
    {
        if (maxsize < totalpath[i].size())
        {
            ans = totalpath[i];
            maxsize = totalpath[i].size();
        }
    }
    if (ans.size() > 0)
    {
        cout << ans.size() << endl;
        for (int i : ans)
        {
            cout << i << " ";
        }
    }
    else
    {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}