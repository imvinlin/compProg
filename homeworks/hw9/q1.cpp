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
  int matched, open, close;
};

Node tree[4'000'005];
string s;

Node merge(Node l, Node r) {
  int m = min(l.open, r.close);
  return {l.matched + r.matched + m, l.open - m + r.open, l.close + r.close - m};
}

void build(int v, int tl, int tr) {
  if (tl == tr) {
    tree[v] = {0, s[tl] == '(' ? 1 : 0, s[tl] == ')' ? 1 : 0};
    return;
  }
  int tm = (tl+tr)/2;
  build(2*v, tl, tm);
  build(2*v+1, tm+1, tr);
  tree[v] = merge(tree[2*v], tree[2*v+1]);
}

Node query(int v, int tl, int tr, int l, int r) {
  if (l > tr || r < tl) return {0, 0, 0};
  if (l <= tl && tr <= r) return tree[v];
  int tm = (tl+tr)/2;
  return merge(query(2*v, tl, tm, l, r), query(2*v+1, tm+1, tr, l, r));
}

static void solve_one() {
  cin >> s;
  int n = s.size();
  build(1, 0, n-1);
  int m; cin >> m;
  forn(i, m) {
    int l, r; cin >> l >> r;
    l--; r--;
    Node res = query(1, 0, n-1, l, r);
    cout << 2 * res.matched << '\n';
  }
}

int main() {
    fast_io();

    solve_one();

    // int T; cin >> T;
    // while (T--) solve_one();

    return 0;
}
