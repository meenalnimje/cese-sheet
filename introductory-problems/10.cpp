#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
int main()
{
    string s;
    cin >> s;
    unordered_map<char, int> map;
    for (int i = 0; i < s.size(); i++)
    {
        map[s[i]]++;
    }
    int count = 0;
    for (auto it = map.begin(); it != map.end(); it++)
    {
        if (it->second % 2 == 1)
        {
            count++;
        }
    }
    if (count > 1)
    {
        cout << "NO SOLUTION" << endl;
    }
    else
    {
        char ch;
        string temp = "";
        for (auto it = map.begin(); it != map.end(); it++)
        {
            if (it->second % 2 == 1)
            {
                ch = it->first;
            }
            else
            {
                for (int i = 0; i < it->second / 2; i++)
                {
                    temp += it->first;
                }
            }
        }
        sort(temp.begin(), temp.end());
        string temp2 = temp;
        reverse(temp2.begin(), temp2.end());
        // cout << temp2 << endl;
        for (int i = 0; i < map[ch]; i++)
        {
            temp += ch;
        }
        temp += temp2;
        cout << temp << endl;
    }
    return 0;
}