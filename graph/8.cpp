#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>
#include <map>
#include <vector>
using namespace std;
bool check(int x, int y, int n, int m)
{
    if (x == n - 1 || y == m - 1 || x == 0 || y == 0)
    {
        return true;
    }
    return false;
}
vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
map<pair<int, int>, char> dirmap = {
    {{0, 1}, 'R'},
    {{1, 0}, 'D'},
    {{-1, 0}, 'U'},
    {{0, -1}, 'L'}};
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> arr(n, vector<char>(m));
    pair<int, int> start;
    vector<pair<int, int>> monsters;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 'M')
            {
                monsters.push_back({i, j});
            }
            else if (arr[i][j] == 'A')
            {
                start = {i, j};
            }
        }
    }
    vector<vector<int>> celltime(n, vector<int>(m, INT_MAX));
    queue<pair<int, int>> q;
    for (int i = 0; i < monsters.size(); i++)
    {
        // q me push karo
        int x = monsters[i].first;
        int y = monsters[i].second;
        q.push({x, y});
        celltime[x][y] = 0;
    }
    while (!q.empty())
    {
        pair<int, int> top = q.front();
        q.pop();
        for (int i = 0; i < dir.size(); i++)
        {
            int newr = top.first + dir[i][0];
            int newcol = top.second + dir[i][1];
            if (newcol >= 0 && newr >= 0 && newcol < m && newr < n && arr[newr][newcol] != '#' && celltime[newr][newcol] > celltime[top.first][top.second] + 1)
            {
                celltime[newr][newcol] = celltime[top.first][top.second] + 1;
                q.push({newr, newcol});
            }
        }
    }
    queue<pair<int, pair<int, int>>> q2;
    q2.push({start.first, {start.second, 0}});
    vector<vector<int>> visited(n, vector<int>(m, 0));

    // parent for pathconstruction
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));

    visited[start.first][start.second] = 1;
    pair<int, int> endCell;
    bool flag = false;

    while (!q2.empty())
    {
        pair<int, pair<int, int>> top = q2.front();
        int x = top.first;
        int y = top.second.first;
        int time = top.second.second;
        q2.pop();

        if (check(x, y, n, m))
        {
            endCell = {x, y};
            flag = true;
            break;
        }

        for (int i = 0; i < dir.size(); i++)
        {
            int newr = x + dir[i][0];
            int newcol = y + dir[i][1];
            if (newcol >= 0 && newr >= 0 && newcol < m && newr < n && arr[newr][newcol] != '#' && !visited[newr][newcol] && time + 1 < celltime[newr][newcol])
            {
                visited[newr][newcol] = 1;
                parent[newr][newcol] = {x, y};
                q2.push({newr, {newcol, time + 1}});
            }
        }
    }
    if (flag)

    {
        cout << "YES" << endl;
        string path;
        pair<int, int> current = endCell;

        while (current != start)
        {
            pair<int, int> prev = parent[current.first][current.second];
            int dx = current.first - prev.first;
            int dy = current.second - prev.second;
            path.push_back(dirmap[{dx, dy}]);
            current = prev;
        }
        reverse(path.begin(), path.end());
        cout << path.length() << endl;
        cout << path << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
