// Bob is a florist who owns a field in the form of a grid of m×n cells. He has planted different types of flowers in the field, n io gets an order for a large bouquet, with the requirement that the bouquet can contain at most two typen of flowers. Bob he job as quickly as possible, he decides to pick flowers from the largest connected area where he can move easily betwi whe where to start from

// Ie a program to help Bob find the largest connected area which has only one or two types of flowers, and print the num
// D the input from STDIN and print the output to STDOUT. Do not print arbitrary strings anywhere in the program, as thes
// Constraints:
// I) 1<m m<=2000
// ii) T<=n<=2000

// Input Format:
// First line has two integers m and n, which are the dimensions of the field.
// Next m lines have n integers each, separated by a single white space. Each unique integer represents a unique type of flon
// Output Format:
// Single line of output should have p, which is the number of cells covered.

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int dfs(int i, int j, vector<vector<int>> &visited, set<int> &st, vector<vector<int>> &grid, int m, int n)
{
    if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j])
    {
        return 0;
    }
    if (!st.count(grid[i][j]))
    {
        if (st.size() == 2)
        {
            return 0;
        }
        else
        {
            st.insert(grid[i][j]);
        }
    }
    visited[i][j] = 1;
    int res = 1;
    for (int k = 0; k < dir.size(); k++)
    {
        int newr = i + dir[k][0];
        int newcol = j + dir[k][1];
        res += dfs(newr, newcol, visited, st, grid, m, n);
    }
    return res;
}
int solve(vector<vector<int>> &grid, int m, int n)
{
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            vector<vector<int>> visited(m, vector<int>(n, 0));
            set<int> st;
            ans = max(ans, dfs(i, j, visited, st, grid, m, n));
        }
    }
    return ans;
}
int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n));

    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            cin >> grid[i][j];

    cout << solve(grid, m, n) << endl;

    return 0;
}