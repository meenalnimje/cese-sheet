#include <iostream>
using namespace std;

int findpower(long long n, long long p)
{
    int count = 0;
    while (n > 0)
    {
        count += n / p;
        n /= p;
    }
    return count;
}

int main()
{
    long long n;
    cin >> n;

    int m = findpower(n, 2);
    int ndash = findpower(n, 5);

    cout << min(m, ndash) << endl;
    return 0;
}
