#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long solve(vector<long long>&arr, int n){
    sort(arr.begin(),arr.end());
    long long sum=1;
    for(int i=0;i<n;i++){
        if(sum<arr[i]){
           break;
        }
        sum+=arr[i];
    }
    return sum;
}
int main(){
    int n;
    cin>>n;
    vector<long long>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<solve(arr,n)<<endl;
    return 0;
}