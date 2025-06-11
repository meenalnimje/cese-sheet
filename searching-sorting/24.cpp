#include <iostream>
#include <vector>
#include<unordered_map>
using namespace std;
using ll = long long;
vector<int>find(vector<ll>arr,ll sum, int idx){
    unordered_map<ll,int>map;
    for(int i=0;i<arr.size();i++){
        if(i!=idx){
            ll tempsum=sum-arr[i];
            if(map.find(tempsum)!=map.end()){
                return {i,map[tempsum]};
            }else{
                map[arr[i]]=i;
            }
        }
    }
    return {-1,-1};
}
int main()
{
    int n;
    cin >> n;
    ll x;
    cin >> x;

    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> position;
    for (int i = 0; i < n; i++)
    {
        ll sum = x - arr[i];
        vector<int>temp=find(arr,sum,i);
        if(temp[0]!=-1 && temp[1]!=-1){
            position={i,temp[0],temp[1]};
            break;
        }
    }
    if(position.size()==0){
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{
        for(int i:position){
            cout<<i+1<<" ";
        }
        cout<<endl;
    }


    return 0;
}
