#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    long long k;
    cin>>k;
    vector<long long>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<long long >brr(m);
    unordered_map<long long,int>map;
    for(int i=0;i<m;i++){
        cin>>brr[i];
        map[brr[i]]++;
    }
    int count=0;
    for(int i=0;i<n;i++){
        long long op1=arr[i]-k;
        long long op2=arr[i]+k;
        // check in brr is there an element b/w op1 and op2 or not
        
    }
    cout<<count<<endl;
    return 0;
}