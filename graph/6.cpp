#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
using namespace std;
bool iscycle(vector<int>&path,int i,int parent ,vector<int>&visited,unordered_map<int,list<int>>&adjlist){
    // updtae the code
    path.push_back(i);
    visited[i]=1;
    for(auto it:adjlist[i]){
        if(visited[it]==1 &&  it!=parent){
            if(iscycle(path,it,i,visited,adjlist)){
                return true;
            }
        }
    }
    path.pop_back();

}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>edges(m);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        edges[i]={x,y};
    }
    unordered_map<int,list<int>>adjlist;
    for(int i=0;i<m;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    vector<int>visited(n+1,0);
    vector<int>path;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            iscycle(path,i,-1,visited,adjlist);
        }
    }

    return 0;

}