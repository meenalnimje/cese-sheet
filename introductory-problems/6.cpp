#include <iostream>
#include <cmath>
using namespace std;
long long solve(long long n)
{
    return pow(2, n);
}

int main()
{
    long long n;
    cin >> n;
    cout << solve(n);
    return 0;
}
