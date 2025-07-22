#include <iostream>
#include <vector>
//https://leetcode.com/problems/maximum-performance-of-a-team/description/
#include <unordered_set>
#include <unordered_map>
#include <list>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(m);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        edges[i] = {u, v};
    }
    unordered_map<int, list<int>> adjlist;
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }

    return 0;
}