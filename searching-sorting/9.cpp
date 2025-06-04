// Given an array of n integers, your task is to find the maximum sum of values in a contiguous, nonempty subarray.
// Input
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
using ll =long long;
int main(){
    int n;
    cin>>n;
    vector<ll>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    ll maxsum=LLONG_MIN;
    ll sum=0;
    for(int i=0;i<n;i++){
        if(sum<0){
            sum=0;
        }
        sum+=arr[i];
        maxsum=max(maxsum,sum);
    }
    cout<<maxsum<<endl;

    return 0;
}