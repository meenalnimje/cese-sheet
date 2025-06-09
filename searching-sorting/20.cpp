#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;
using ll = long long;

// room allocation 
int main()
{
    int n;
    cin >> n;
    vector<vector<ll>> combine(n);
    for (int i = 0; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        combine[i] = {x, y, i };
    }
    sort(combine.begin(), combine.end());
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;
    vector<ll> ans(n);
    ll roomid = 0;
    for (int i = 0; i < n; i++)
    {
        ll idx = combine[i][2];
        if (!pq.empty() && pq.top().first < combine[i][0])
        {
            int roomno = pq.top().second;
            pq.pop();
            ans[idx] = roomno;
            pq.push({combine[i][1], roomno});
        }
        else
        {
            
            roomid++;
            ans[idx]=roomid;
            pq.push({combine[i][1],roomid});
        }
    }
    cout<<roomid<<endl;
    for(int x:ans){
        cout<<x<<" ";
    }
    return 0;
}