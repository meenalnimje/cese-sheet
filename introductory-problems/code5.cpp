#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        for (int i = 0; i < x; i++)
        {
            cout<<i<<" ";
        }
        for (int i = x + 1; i < n; i++)
        {
            cout<<i<<" ";
        }
        if(x<n){
            cout<<x;
        }
        cout << endl;
    }
    return 0;
}
