#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int calculateRounds(const unordered_map<int, int> &pos, int n) {
    int rounds = 1;
    for (int i = 2; i <= n; i++) {
        if (pos.at(i) < pos.at(i - 1)) {
            rounds++;
        }
    }
    return rounds;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    vector<pair<int, int>> swaps(m);
    unordered_map<int, int> pos;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        pos[arr[i]] = i;
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        swaps[i] = {a - 1, b - 1};  
    }

    for (int i = 0; i < m; i++) {
        
    }

    return 0;
}
