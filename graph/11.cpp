#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
#include <queue>
#include <list>
using namespace std;
using pi = pair<int, int>;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(m);
    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        edges[i] = {x, y, w};
    }
    // isme path save karungi along with cost.

    vector<pair<int, int>> path;

    // sabse pehle minimum path nikalo using dijkstra.
    unordered_map<int, list<pair<int, int>>> adjlist;
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        adjlist[u].push_back({v, w});
    }
    //
    vector<int> distance(n + 1, INT_MAX),visited(n+1,0);
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.push({0, 1});
    while(!pq.empty()){
        pair<int,int>top=pq.top();
        pq.pop();
        if(visited[top.second]==1){
            continue;
        }
        visited[top.second]=1;
        for(auto it: adjlist[top.second]){
            
        }

    }

    return 0;
}