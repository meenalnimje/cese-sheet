#include <iostream>
#include <deque>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    deque<int> dq;
    for (int i = 1; i <= n; ++i)
    {
        dq.push_back(i);
    }
    vector<int> ans;
    bool skip = true;
    while (!dq.empty())
    {
        int current = dq.front();
        dq.pop_front();
        if (skip)
        {
            dq.push_back(current);
        }
        else
        {
            ans.push_back(current);
        }
        skip = !skip;
    }
    for (auto x : ans)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}