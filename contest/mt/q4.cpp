#include <bits/stdc++.h>
using namespace std;

static inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

static void solve_one() {
    int n; 
    long long k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    sort(a.begin(), a.end());

    long long lo = 0, hi = a[n-1]-a[0];
    while (lo < hi) {
        long long mid = (lo+hi)/2;
        long long cnt = 0;
        for (int i = 0; i < n; i++)
            cnt += upper_bound(a.begin()+i+1, a.end(), (long long)a[i]+mid) - (a.begin()+i+1);
        if (cnt >= k) hi = mid;
        else lo = mid + 1;
    }
    cout << lo;
}

int main() {
    fast_io();
    solve_one();
    return 0;
}
