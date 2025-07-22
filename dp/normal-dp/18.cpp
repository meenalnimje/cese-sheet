#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }
    for(int i=0;i<=m;i++){
        dp[0][i]=0;
    }
    dp[1][1]=0;
    dp[1][2]=1;
    dp[2][1]=1;
    for(int i=2;i<=n;i++){
        for(int j=2;j<=m;j++){
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
    }
    cout<<dp[n][m]<<endl;
    return 0;

}