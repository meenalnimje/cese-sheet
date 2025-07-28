#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
long long min(long long a, long long b)
{
    if (a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
long long solve(int idx, long long currsum, long long total, vector<long long> arr)
{
    if (idx == arr.size())
    {
        return abs(total - 2 * currsum);
    }
    long long take = solve(idx + 1, currsum + arr[idx], total, arr);
    long long notake = solve(idx + 1, currsum, total, arr);
    return min(take, notake);
}
int main()
{
    int n;
    cin >> n;
    vector<long long> arr(n);
    long long total = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        total += arr[i];
    }
    // idx , curr sum, totalsum,
    long long ans = solve(0, 0, total, arr);
    cout << ans << endl;
    return 0;
}