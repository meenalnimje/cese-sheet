#include <iostream>
#include <vector>
#include <unordered_set>
#include <climits>
using namespace std;
using ll=long long ;
ll max(ll a,ll b){
    if(a>b) return a;
    return b;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    unordered_set<ll> map;
    int i = 0;
    ll ans = LLONG_MIN;
    int j = 0;
    while (j < n)
    {
        if (map.find(arr[j]) == map.end())
        {
            map.insert(arr[j]);
            ans = max(ans, j - i + 1);
            j++;
        }
        else
        {
            // shrink the window
            map.erase(arr[i]);
            i++;
        }
    }
    cout << ans << endl;
    return 0;
}