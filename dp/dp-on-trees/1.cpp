// //  Given a Tree of “N” nodes; find the height of each node and print it ; the tree is rooted at Node-1.

#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
#include <list>
using namespace std;
void dfs(int i, vector<int> &visited, vector<int> &height, unordered_map<int, list<int>> &adjlist, vector<int> &parents)
{
    visited[i] = 1;
    for (auto it : adjlist[i])
    {
        if (!visited[it])
        {
            parents[it] = i;
            dfs(it, visited, height, adjlist, parents);
        }
    }
    int h = 0;
    for (auto it : adjlist[i])
    {
        if (it != parents[i])
        {
            h = max(h, height[it]);
        }
    }
    height[i] = 1 + h;
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
        adjlist[v].push_back(u);
    }
    vector<int> visited(n + 1, 0), parents(n + 1, 0);
    vector<int> height(n + 1, 0);
    dfs(1, visited, height, adjlist, parents);
    cout << height[1] << endl;
    return 0;
}