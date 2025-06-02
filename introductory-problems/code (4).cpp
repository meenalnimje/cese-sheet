// ques -2 : Missing  number

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int main()
{
    long long n;
    cin >> n;
    vector<long long> arr(n - 1);
    long long sum = 0;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    long long actualsum = (n * (n + 1)) / 2;
    long long ans = actualsum - sum;
    cout << ans << endl;

    return 0;
}
