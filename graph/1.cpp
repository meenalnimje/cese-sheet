#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<map>
using namespace std;

vector<pair<int,int>> dir = {{0,-1}, {0,1}, {1,0}, {-1,0}};

int dfs(int i, int j, vector<vector<int>>& visited, vector<vector<char>>& arr) {
    visited[i][j] = 1;
    for (int k = 0; k < dir.size(); k++) {
        int newrow = i + dir[k].first;
        int newcol = j + dir[k].second;
        if (newrow >= 0 && newrow < arr.size() && newcol >= 0 && newcol < arr[0].size() &&
            arr[newrow][newcol] != '#' && visited[newrow][newcol] != 1) {
            dfs(newrow, newcol, visited, arr);
        }
    }
    return 1;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> arr(n, vector<char>(m));
    map<pair<int, int>, int> places;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == '.') {
                places[{i, j}]++;
            }
        }
    }

    vector<vector<int>> visited(n, vector<int>(m, 0));
    int count = 0;

    for (auto it = places.begin(); it != places.end(); it++) {
        int i = it->first.first;
        int j = it->first.second;
        if (!visited[i][j]) {
            if (dfs(i, j, visited, arr) != -1) {
                count++;
            }
        }
    }

    cout << count << endl;
    return 0;
}
