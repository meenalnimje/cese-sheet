#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> dir = {{1, 0}, {0, 1}};
void solve(int i, int j, vector<string> &temp, string str, vector<vector<char>> &arr, vector<vector<int>> &visited)
{
    str.push_back(arr[i][j]);
    visited[i][j] = 1;
    if (i == arr.size() - 1 && j == arr[0].size() - 1)
    {
        temp.push_back(str);
        visited[i][j] = 0;
        return;
    }
    for (int k = 0; k < dir.size(); k++)
    {
        int newr = i + dir[k][0];
        int newcol = j + dir[k][1];
        if (newr >= 0 && newr < arr.size() && newcol >= 0 && newcol < arr[0].size() && !visited[newr][newcol])
        {
            solve(newr, newcol, temp, str, arr, visited);
        }
    }
    visited[i][j] = 0;
}
int main()
{
    int n;
    cin >> n;
    vector<vector<char>> arr(n, vector<char>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    vector<string> temp;
    string str = "";
    vector<vector<int>> visited(n, vector<int>(n, 0));
    solve(0, 0, temp, str, arr, visited);
    sort(temp.begin(), temp.end());
    cout << temp[0];
    return 0;
}