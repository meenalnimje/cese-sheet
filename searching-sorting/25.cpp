#include <iostream>
#include <vector>
#include <stack>
using namespace std;
using ll = long long;
using pi = pair<ll, ll>;
int main()
{
    int n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> ans(n, 0);
    stack<pi> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && st.top().first >= arr[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            ans[i] = 0;
        }
        else
        {
            ans[i] = st.top().second + 1;
        }
        st.push({arr[i], i});
    }
    for (int i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}