#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll=long long;
int main(){
    int n;
    cin>>n;
    vector<ll>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    ll ans;
    if(n%2==0){
        int mid1=n/2;
        int mid2=(n/2)+1;
        ll sum1=0,sum2=0;
        for(int i=0;i<n;i++){
            sum1+=abs(arr[mid1]-arr[i]);
            sum2+=abs(arr[mid2]-arr[i]);
        }
        ans=min(sum1,sum2);
    }
    else{
        int mid=n/2;
        ll sum=0;
        for(int i=0;i<n;i++){
            sum+=abs(arr[mid]-arr[i]);
        }
        ans=sum;
    }
    cout<<ans<<endl;

    return 0;
}