#include <iostream>
#include <vector>
#include <climits>
using namespace std;
// longest incresing subsequnce using binary search and dp
// O(n logn);
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> temp;
    for (int x : arr)
    {
        auto it = lower_bound(temp.begin(), temp.end(), x);
        if (it == temp.end())
        {
            temp.push_back(x);
        }
        else
        {
            *it = x;
        }
    }
    int ans = temp.size();
    cout << ans << endl;

    return 0;
}