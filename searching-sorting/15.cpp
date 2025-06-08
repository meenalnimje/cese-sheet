#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using ll = long long;
using namespace std;
ll max(ll a, ll b)
{
    if (a > b)
    {
        return a;
    }
    return b;
}
int main()
{
    int x, n;
    cin >> x >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    priority_queue<ll> pq;
    pq.push(1);
    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
        priority_queue<ll> temp = pq;
        ll var = x;
        ll sum = INT_MIN;
        while (!pq.empty())
        {
            ll len=var-(pq.top()+1)+1;
            sum = max(sum,len);
            var = pq.top();
            pq.pop();
        }
        pq = temp;
        cout << sum << " ";
    }

    return 0;
}