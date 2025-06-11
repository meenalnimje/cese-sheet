#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
map<pair<int, int>, char> mapdir = {
    {{0, 1}, 'R'},
    {{1, 0}, 'D'},
    {{0, -1}, 'L'},
    {{-1, 0}, 'U'},
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> arr(n, vector<char>(m));
    pair<int, int> start, end;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 'A')
            {
                start = {i, j};
            }
            else if (arr[i][j] == 'B')
            {
                end = {i, j};
            }
        }
    }

    // use bfs
    vector<vector<int>> visited(n, vector<int>(m, 0));
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));
    queue<pair<int, int>> q;
    q.push(start);
    visited[start.first][start.second] = 1;

    bool flag = false;

    while (!q.empty())
    {
        pair<int, int> top = q.front();
        q.pop();

        if (top == end)
        {
            flag = true;
            break;
        }

        for (int k = 0; k < dir.size(); k++)
        {
            int newrow = top.first + dir[k].first;
            int newcol = top.second + dir[k].second;
            if (newrow >= 0 && newrow < n && newcol >= 0 && newcol < m &&
                visited[newrow][newcol] == 0 &&
                (arr[newrow][newcol] == '.' || arr[newrow][newcol] == 'B'))
            {
                visited[newrow][newcol] = 1;
                parent[newrow][newcol] = top;
                q.push({newrow, newcol});
            }
        }
    }

    if (flag)
    {
        string path = "";
        pair<int, int> curr = end;
        while (curr != start)
        {
            pair<int, int> prev = parent[curr.first][curr.second];
            int dx = curr.first - prev.first;
            int dy = curr.second - prev.second;
            path += mapdir[{dx, dy}];
            curr = prev;
        }
        reverse(path.begin(), path.end());
        cout << "YES" << endl;
        cout << path.size() << endl;
        cout << path << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
