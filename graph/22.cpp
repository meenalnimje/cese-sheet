#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <list>
using namespace std;
void bfs(unordered_map<int, list<int>> &tempadjlist, int i, vector<int> &ans, vector<int> &visited, int count)
{
    queue<int> q;
    visited[i] = 1;
    q.push(i);
    while (!q.empty())
    {
        int top = q.front();
        q.pop();
        ans[top] = count;
        for (auto it : tempadjlist[top])
        {
            if (!visited[it])
            {
                visited[it] = 1;
                q.push(it);
            }
        }
    }
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
    vector<int> ans(n + 1, 0);
    int count = 0;
    vector<int> visited(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            count++;
            bfs(adjlist, i, ans, visited, count);
        }
    }
    count = 0;
    fill(visited.begin(), visited.end(), 0);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            count++;
            bfs(reverseadj, i, ans, visited, count);
        }
    }
    unordered_map<int, int> temp;
    for (int i = 1; i < ans.size(); i++)
    {
        temp[ans[i]]++;
    }
    cout << temp.size() << endl;
    for (int i = 1; i < ans.size(); i++)
    {
        cout << ans[i] - 1 << " ";
    }
    cout << endl;

    return 0;
}