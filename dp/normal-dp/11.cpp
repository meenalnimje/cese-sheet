#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    vector<vector<int>> dp(a + 1, vector<int>(b + 1, INT_MAX));
    for (int i = 0; i <= min(a, b); i++)
    {
        dp[i][i] = 0;
    }
    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            // horizontal cut
            // length remain constant 
            // will go from bredth =1 to b
            for(int k=1;k<j;k++){
                dp[i][j]=min(dp[i][j],1+dp[i][k]+dp[i][j-k]);
            }
            
            // vertical cut
            // will go from length =1 to a
            for(int k=1;k<i;k++){
                dp[i][j]=min(dp[i][j],1+dp[k][j]+dp[i-k][j]);
            }
        }
    }
    cout << dp[a][b]<<endl;
    return 0;
}