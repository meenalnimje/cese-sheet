#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
using ll=long long;
int main(){
    int n;
    cin>>n;
    vector<ll>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    unordered_map<ll,ll>map;
    ll sum=0;
    ll count=0;
    map[0]=1;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        ll mod = (sum % n + n) % n;  // to handle negative sum
        count+=map[mod];
        map[mod]++;

    }
    cout<<count<<endl;
    return 0;
}