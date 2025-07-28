#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string s;
    cin >> s;
    sort(s.begin(),s.end());
    vector<string> temp;
    do
    {
        temp.push_back(s);
    } while (next_permutation(s.begin(), s.end()));

    cout << temp.size() << endl;
    for (int i = 0; i < temp.size(); i++)
    {
        cout << temp[i] << endl;
    }
    return 0;
}
