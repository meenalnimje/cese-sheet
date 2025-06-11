#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
using namespace std;
void dfs(int i, unordered_map<int, list<int>> &adjlist, vector<int> &components, vector<int> &visited)
{
    visited[i] = 1;
    components.push_back(i);
    for (auto it : adjlist[i])
    {
        if (!visited[it])
        {
            dfs(it, adjlist, components, visited);
        }
    }
}
int min(int a,int b){
    if(a<b) return a;
    return b;
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
    vector<int> visited(n+1, 0);
    vector<vector<int>> comp;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            vector<int> components;
            dfs(i, adjlist, components, visited);
            comp.push_back(components);
        }
    }
    int minroads = comp.size() - 1;
    cout << minroads << endl;
    for (int i = 1; i < comp.size(); i++) {
        cout << comp[i - 1][0] << " " << comp[i][0] << endl;
    }
    return 0;
}
