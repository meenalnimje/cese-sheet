#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <list>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(m);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        edges[i] = {x, y};
    }
    unordered_map<int, list<int>> adjlist;
    vector<int> indegree(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adjlist[u].push_back(v);
        indegree[v]++;
    }
    queue<int> q;
    vector<int> ans;
    for(int i=1;i<=n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int top=q.front();
        q.pop();
        ans.push_back(top);
        for(auto it:adjlist[top]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }
    }
    if(ans.size()==n){
        for(int i:ans){
            cout<<i<<" ";
        }
    }
    else{
        cout<<"IMPOSSIBLE"<<endl;
    }

    return 0;
}