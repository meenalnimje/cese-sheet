#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
bool check(ll mid,vector<ll> &arr, int k, int n){
    ll sum=0;
    ll count=1;
    for(int i=0;i<n;i++){
        if(arr[i]>mid) return false;
        if(sum+arr[i]>mid){
            sum=arr[i];
            count++;
        }
        else{
            sum+=arr[i];
        }
    }
    return count<=k;
}
ll solve(vector<ll> &arr, int k, int n, ll sum)
{
    ll ans=-1;
    ll low=1,high=sum;
    while(low<=high){
        ll mid= low+(high-low)/2;
        if(check(mid,arr,k,n)){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}
int main()
{
    int n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    cout << solve(arr, k, n, sum) << endl;

    return 0;
}