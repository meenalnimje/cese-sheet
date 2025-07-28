#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    long long sum = (1LL * n * (n + 1)) / 2;
    if (sum % 2 != 0)
    {
        cout << "NO" << endl;
    }
    else
    {
        vector<int> ans1, ans2;
        long long target = sum / 2;
        for (int i = n; i >= 1; i--)
        {
            if (target >= i)
            {
                ans1.push_back(i);
                target -= i;
            }
            else
            {
                ans2.push_back(i);
            }
        }
        if (ans1.size() == 0)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
            cout << ans1.size() << endl;
            for (int i = 0; i < ans1.size(); i++)
            {
                cout << ans1[i] << " ";
            }
            cout << endl;
            cout << ans2.size() << endl;
            for (int i = 0; i < ans2.size(); i++)
            {
                cout << ans2[i] << " ";
            }
        }
    }
    return 0;
}