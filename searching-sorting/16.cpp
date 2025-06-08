// Distinct Values Subarrays
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
    int i=0;
    unordered_map<ll,ll>map;
    ll total=0;
    for(int j=0;j<n;j++){
        while(map.find(arr[j])!=map.end()){
            map[arr[i]]--;
            if(map[arr[i]]==0){
                map.erase(arr[i]);
            }
            i++;
        }
        map[arr[j]]++;
        total+=(j-i+1);
    }
    cout<<total<<endl;
    return 0;
}