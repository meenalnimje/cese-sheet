#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

// maximum number of overlapping intervals
using namespace std;
using ll = long long;
bool check(int i, int j, vector<vector<int>> &time)
{
    if (time[j][0] >= time[i][0] && time[j][1] <= time[i][1])
    {
        return true;
    }
    return false;
}
int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> intervals;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        intervals.push_back({x, +1});
        intervals.push_back({y, -1});
    }
    sort(intervals.begin(), intervals.end());
    int person = 0;
    int maxans = INT_MIN;
    for (auto it : intervals)
    {
        person += it.second;
        maxans = max(maxans, person);
    }
    cout << maxans << endl;
    return 0;
}