#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()

static inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

static void solve_one() {
    int n; cin >> n;

    unordered_map<int, vector<int>> past; // key : indexes
    vector<int> sol (n + 1);
    int temp;

    for (int i = 0; i < n; ++i) {
        cin >> temp;
        past[temp].push_back(i);
        sol[i + 1] = sol[i];

        if ((int)past[temp].size() >= temp) {
            int index = past[temp][past[temp].size() - temp];
            sol[i + 1] = max(sol[i + 1], sol[index] + temp);
        }
    }

    cout << sol[n] << "\n";
}

int main() {
    fast_io();

    int T; cin >> T;
    while (T--) solve_one();

    return 0;
}
