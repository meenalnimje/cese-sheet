#include <iostream>
#include <vector>
using namespace std;
long long solve(vector<long long> &arr, int n)
{
    long long count = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[i - 1])
        {
            count += abs(arr[i] - arr[i - 1]);
            arr[i] = arr[i - 1];
        }
    }
    return count;
}
int main()
{
    int n;
    cin >> n;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << solve(arr, n) << endl;
    return 0;
}