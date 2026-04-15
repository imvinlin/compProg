#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i,a,b) for (int i = (a); i <= (b); i++)
#define forn(i,n) for (int i = 0; i < (n); i++)
#define rforn(i,n) for (int i = (n)-1; i > -1; i--)
#define rdvec(a,n) do { forn(i,n) cin >> a[i]; } while(0)
#define print(x) (cout<<#x<<"="<<(x)<<"\n")

static inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

static void solve_one() {
    string s; cin >> s;
    int q; cin >> q;

    set<int> pos[26];
    forn(i, (int)s.size()) {
        pos[s[i] - 'a'].insert(i);
    }

    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int p; char c; cin >> p >> c;
            p--;
            pos[s[p] - 'a'].erase(p);
            s[p] = c;
            pos[c - 'a'].insert(p);
        } else {
            int l, r; cin >> l >> r;
            l--; r--;
            int ans = 0;
            forn(i, 26) {
                auto it = pos[i].lower_bound(l);
                if (it != pos[i].end() && *it <= r) ans++;
            }
            cout << ans << '\n';
        }
    }
}

int main() {
    fast_io();

    solve_one();

    return 0;
}
