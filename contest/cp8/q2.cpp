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

struct Node {
    int zeros, ones;
};

constexpr int MAXN = 4 * 200005;
Node tree[MAXN];
string s;
int n;

Node merge(Node a, Node b) {
    int matched = min(a.zeros, b.ones);
    return {a.zeros - matched + b.zeros, a.ones - matched + b.ones};
}

void build(int v, int tl, int tr) {
    if (tl == tr) {
        if (s[tl] == '0') tree[v] = {1, 0};
        else tree[v] = {0, 1};
        return;
    }
    int tm = (tl+tr)/2;
    build(2*v, tl, tm);
    build(2*v+1, tm+1,tr);
    tree[v] = merge(tree[2*v],tree[2*v+1]);
}

void update(int v, int tl, int tr, int pos) {
    if (tl == tr) {
        if (s[tl] == '0') s[tl] = '1';
        else s[tl] = '0';
        
        if (s[tl] == '0') tree[v] = {1, 0};
        else tree[v] = {0, 1};
        
        return;
    }
    int tm = (tl+tr)/2;
    if (pos <= tm) update(2*v, tl, tm, pos);
    else update(2*v+1, tm+1, tr, pos);
    tree[v] = merge(tree[2*v], tree[2*v+1]);
}

Node query(int v, int tl, int tr, int l, int r) {
    if (l > r) return {0, 0};
    if (l == tl && r == tr) return tree[v];
    int tm = (tl+tr)/2;
    return merge(
        query(2*v, tl, tm, l, min(r, tm)),
        query(2*v+1, tm+1, tr, max(l, tm+1), r)
    );
}

static void solve_one() {
    cin >> s;
    n = s.size();
    build(1, 0, n-1);
    int q; cin >> q;
    while (q--) {
        int k; cin >> k;
        if (k == 1) {
            int x; cin >> x;
            x--;
            update(1, 0, n-1, x);
        } else {
            int l, r; cin >> l >> r;
            l--; r--;
            Node res = query(1, 0, n-1, l, r);
            cout << res.zeros + res.ones << "\n";
        }
    }
}

int main() {
    fast_io();

    solve_one();

    return 0;
}
