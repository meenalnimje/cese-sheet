#include <iostream>
using namespace std;
int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long a, b;
        cin >> a >> b;
        long long total = a + b;
        if (total % 3 == 0 && min(a, b) * 2 >= max(a, b))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}