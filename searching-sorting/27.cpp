#include<iostream>
#include<vector>
using namespace std;
using ll=long long;
int solve(vector<ll>arr,ll x){
    ll sum=0;
    int count=0;
    int n=arr.size();
    for(int i=0;i<n;i++){
        if(sum<0){
            sum=0;
        }
        if(sum>x){
            count++;
        }
        sum+=arr[i];
    }
}
int main(){
    int n;
    cin>>n;
    ll x;
    cin>>x;
    vector<ll>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int xdash=solve(arr,x);
    int xlessdash=solve(arr,x-1);
    cout<<xdash-xlessdash<<endl;
    return 0;
} 
