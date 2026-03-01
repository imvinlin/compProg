#include <bits/stdc++.h>
using namespace std;

static inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

static void solve_one() {
    int n; cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    map<string, int> freq;
    for (auto& x : a) freq[x]++;

    int cnt = 0;
    for (auto& s : a) {
        int m = (int)s.size();
        bool isKey = false;

        for (int p = 1; p < m; p++) {
            string left = s.substr(0, p);
            string right = s.substr(p);

            if (left == right) isKey = freq[left] >= 2;
            else isKey = freq[left] >= 1 && freq[right] >= 1;

            if (isKey) break;
        }
        if (isKey) cnt++;
        if (cnt > 1) break;
    }

    cout << (cnt == 1 ? "YES" : "NO") << "\n";
}

int main() {
    fast_io();

    solve_one();

    return 0;
}
