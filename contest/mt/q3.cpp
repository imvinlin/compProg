#include <bits/stdc++.h>
using namespace std;

static inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

static void solve_one() {
    string s;
    long long k;
    cin >> s >> k;

    int n = (int)s.size();
    long long m = n;

    while (m < k) m *= 2;

    while (m > n) {
        long long h = m/2;
        if (k > h) {
            long long p = k-h-1;
            k = (p-1+h) % h + 1;
        }
        m = h;
    }
    cout << s[k-1];
}

int main() {
    fast_io();

    solve_one();

    return 0;
}
