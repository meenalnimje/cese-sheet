#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
using ll=long long; 
int main()
{
    int n, k;
    cin >> n >> k;
    vector<pair<ll, ll>> arr(n);
    for (int i = 0; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        arr[i] = {y, x};
    }
    sort(arr.begin(), arr.end());
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    ll count=0;
    for(int i=0;i<n;i++){
        ll start=arr[i].second;
        ll end=arr[i].first;
        if(!pq.empty() && pq.top()<=start){
            pq.pop();
            pq.push(end);
            count++;
        }
        else if(pq.size()<k){
            pq.push(end);
            count++;
        }
    }
    cout<<count<<endl;
    return 0;
}