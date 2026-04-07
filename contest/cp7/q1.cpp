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

static map<string, int> compOf = {
    {"BG", 0}, {"RY", 0},
    {"BR", 1}, {"GY", 1},
    {"BY", 2}, {"GR", 2}
};

static bool share(const string& a, const string& b) {
    return a[0] == b[0] || a[0] == b[1] || a[1] == b[0] || a[1] == b[1];
}

static void solve_one() {
    int n, q;
    cin >> n >> q;

    vector<string> type(n+1);

    set<int> mid[3];
    const int INF = 1e9;
    forn(p, 3) mid[p] = {-INF,INF};

    rep(i, 1, n) {
        cin >> type[i];
        int c = compOf[type[i]];
        forn(p, 3) {
            if (p != c) mid[p].insert(i);
        }
    }

    forn(_, q) {
        int x, y;
        cin >> x >> y;

        if (x == y) { cout << 0 << '\n'; continue; }
        if (x > y) swap(x, y);

        if (share(type[x], type[y])) {
            cout << y - x << '\n';
            continue;
        }

        int p = compOf[type[x]];
        ll ans = 2e9;

        auto it = mid[p].lower_bound(x);
        if (*it <= y) {
            ans = y - x;
        } else {
            ans = min(ans, 2LL * (*it) - x - y);
        }
        --it;
        ans = min(ans, (ll)x + y - 2LL * (*it));

        cout << (ans > 1e9 ? -1 : ans) << '\n';
    }
}

int main() {
    fast_io();

    int T; cin >> T;
    while (T--) solve_one();

    return 0;
}
