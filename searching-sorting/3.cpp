#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
long long  check(vector<long long>arr,long long x){
    int n=arr.size();
    int i = 0;
    long long count = 0;
    int j = n-1;
    if(arr[0]>x) return 0;
    while (i <= j)
    {
        if(arr[i]+arr[j]<=x){
            i++;
            j--;

        }
        else{
            j--;
        }
        count++;
    }
    return count;
}
int main()
{
    int n;
    cin >> n;
    long long x;
    cin >> x;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    cout<<check(arr,x)<<endl;
    return 0;
}
