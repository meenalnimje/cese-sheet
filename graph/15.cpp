#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <algorithm>
using namespace std;
 
bool dfs(int node, int parent, unordered_map<int, list<int>> &adjlist, vector<int> &visited, vector<int> &path, vector<int> &cycle_start, vector<int> &parent_track) {
    visited[node] = 1;
    path.push_back(node);
 
    for (int neighbor : adjlist[node]) {
        if (neighbor == parent) continue; // skip the edge back to parent
 
        if (visited[neighbor]) {
            // Cycle detected
            cycle_start.push_back(neighbor);
            path.push_back(neighbor);
            return true;
        } else {
            parent_track[neighbor] = node;
            if (dfs(neighbor, node, adjlist, visited, path, cycle_start, parent_track)) return true;
        }
    }
 
    path.pop_back(); 
    return false;
}
 
int main() {
    int n, m;
    cin >> n >> m;
 
    unordered_map<int, list<int>> adjlist;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
 
    vector<int> visited(n + 1, 0);
    vector<int> parent_track(n + 1, -1);
    vector<int> path;
    vector<int> cycle_start;
 
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, adjlist, visited, path, cycle_start, parent_track)) {
                break;
            }
        }
    }
 
    if (cycle_start.empty()) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        int start = cycle_start[0];
        vector<int> cycle;
        cycle.push_back(start);
        for (int i = path.size() - 2; i >= 0; i--) {
            cycle.push_back(path[i]);
            if (path[i] == start) break;
        }
 
        if (cycle.size() < 4) {
            cout << "IMPOSSIBLE" << endl;
        } else {
            cout << cycle.size() << endl;
            for (int node : cycle) cout << node << " ";
            cout << endl;
        }
    }
 
    return 0;
}