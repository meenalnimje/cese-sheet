#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int i = 0;
    long long count = 0;
    unordered_map<long long, long long> map;
    for (int j = 0; j < n; j++)
    {
        map[arr[j]]++;
        while (map.size() > k)
        {
            map[arr[i]]--;
            if (map[arr[i]] == 0)
            {
                map.erase(arr[i]);
            }
            i++;
        }
        count += (j - i + 1);
    }
    cout << count << endl;
    return 0;
}