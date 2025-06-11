#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
using ll=long long;
bool static comp(pair<ll,ll>&a,pair<ll,ll>&b){
    if(a.first==b.first){
        return a.second>b.second;
    }
    return a.first<b.first;
}
int main(){
    int n;
    cin>>n;
    vector<pair<ll,ll>>arr(n);
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        arr[i]={x,y};
    }
    sort(arr.begin(),arr.end(),comp);
    ll timer=0;
    ll total=0;
    for(int i=0;i<n;i++){
        int finishtime=timer+arr[i].first;
        total+=(arr[i].second-finishtime);
        timer=finishtime;
    }
    cout<<total<<endl;
    return 0;
}