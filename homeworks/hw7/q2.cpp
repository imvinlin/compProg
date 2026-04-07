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

int par[200001], sz[200001];
bool cyc[200001];

int find(int x) {
    return par[x] == x ? x : par[x] = find(par[x]);
}

void unite(int x, int y) {
    x = find(x); y = find(y);
    if (x == y) { cyc[x] = true; return; }
    if (sz[x] < sz[y]) swap(x, y);
    par[y] = x;
    sz[x] += sz[y];
    cyc[x] = cyc[x] || cyc[y];
}

static void solve_one() {
    int n; cin >> n;
    vector<int> a(n+1);
    
    rep(i, 0, n) { 
      par[i] = i;
      sz[i] = 1;
      cyc[i] = false;
    }

    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) {
        if (i < a[i] || a[a[i]] != i)
            unite(i, a[i]);
    }

    int c = 0, p = 0;
    rep(i, 1, n) {
        if (find(i) == i) {
            if (cyc[i]) c++;
            else p++;
        }
    }

    cout << c + (p > 0 ? 1 : 0) << " " << c + p << "\n";
}

int main() {
    fast_io();

    int T; cin >> T;
    while (T--) solve_one();

    return 0;
}
