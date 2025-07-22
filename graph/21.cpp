#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <list>
using namespace std;
// kosaraju algorithm for finding strongly connected components
// goal was to find every city should be visited by every other city 
// so a->b is true then b->a should also be true;

int bfs(unordered_map<int, list<int>> &tempadjlist, int n)
{
    vector<int> visited(n + 1, 0);
    queue<int> q;
    q.push(1);
    visited[1] = 1;

    while (!q.empty())
    {
        int top = q.front();
        q.pop();
        for (int it : tempadjlist[top])
        {
            if (!visited[it])
            {
                visited[it] = 1;
                q.push(it);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
        {
            return i;
        }
    }
    return -1;
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
    unordered_map<int, list<int>> adjlist, reverseadj;
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adjlist[u].push_back(v);
        reverseadj[v].push_back(u);
    }
    int node1 = bfs(adjlist, n);
    if (node1 != -1)
    {
        cout << "NO" << endl;
        cout << 1 << " " << node1 << endl;
        return 0;
    }
    int node2 = bfs(reverseadj, n);
    if (node2 != -1)
    {
        cout << "NO" << endl;
        cout << node2 << " " << 1 << endl;
        return 0;
    }
    cout << "YES" << endl;

    return 0;
}