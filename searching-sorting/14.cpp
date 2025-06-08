#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <climits>
using namespace std;
using ll = long long;
int main()
{
    int n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> map;
    int towerid = 0;
    for (int i = 0; i < n; i++)
    {
        int besttopid = -1;
        int besttop = INT_MAX;
        for (auto it = map.begin(); it != map.end(); it++)
        {
            if (!it->second.empty() && arr[i] < it->second.top() && it->second.top() < besttop)
            {
                besttop = it->second.top();
                besttopid = it->first;
            }
        }
        if (besttopid == -1)
        {
            map[towerid].push(arr[i]);
            towerid++;
        }
        else
        {
            map[besttopid].push(arr[i]);
        }
    }
    cout << map.size();

    return 0;
}