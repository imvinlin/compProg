#include <bits/stdc++.h>
using namespace std;

using ll = long long;
//static const ll INF = (1LL << 62);

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

static int par[1001], rnk[1001];

static int find(int x) {
    while (par[x] != x) x = par[x] = par[par[x]];
    return x;
}

static bool unite(int a, int b) {
    a = find(a); b = find(b);
    if (a == b) return false;
    if (rnk[a] < rnk[b]) swap(a, b);
    par[b] = a;
    if (rnk[a] == rnk[b]) rnk[a]++;
    return true;
}

static void solve_one() {
    int n; cin >> n;

    rep(i,1,n) { par[i] = i; rnk[i] = 0; }

    vector<pair<int,int>> extra;

    forn(i,n-1) {
        int a,b;
        cin >> a >> b;
        if (!unite(a, b)) extra.push_back({a, b});
    }

    vector<int> roots;
    rep(i,1,n) {
        if (find(i) == i) roots.push_back(i);
    }

    cout << (int)extra.size() << '\n';
    forn(i,(int)extra.size()) {
        cout << extra[i].first << ' ' << extra[i].second << ' ' << roots[i] << ' ' << roots[i+1] << '\n';
        unite(roots[i],roots[i+1]);
    }
}

int main() {
    fast_io();

    solve_one();
    

    // int T; cin >> T;
    // while (T--) solve_one();
    

    // int n;
    // while (cin >> n && n != 0){
    //  solve_one(n);
    // }

    return 0;
}

