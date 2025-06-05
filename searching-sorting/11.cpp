#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    unordered_map<int,int>map;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        map[arr[i]]=i;
    }
    int count=1;
    for(int i=2;i<=n;i++){
        if(map[i]<map[i-1]){
            count++;
        }
    
    }
    cout<<count<<endl;
    return 0;
}