#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <list>
#include <stack>
#include <algorithm>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    unordered_map<int, list<int>> adjlist;

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adjlist[x].push_back(y);
        adjlist[y].push_back(x);
    }

    vector<int> visited(n + 1, 0);
    vector<int> parent(n + 1, -1);

    queue<int> q;
    q.push(1);
    visited[1] = 1;

    bool found = false;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        if (node == n)
        {
            found = true;
            break;
        }

        for (auto neighbor : adjlist[node])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = 1;
                parent[neighbor] = node;
                q.push(neighbor);
            }
        }
    }

    if (!found)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        vector<int> path;
        int curr = n;
        while (curr != -1)
        {
            path.push_back(curr);
            curr = parent[curr];
        }
        reverse(path.begin(), path.end());

        cout << path.size() << endl;
        for (auto node : path)
        {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
