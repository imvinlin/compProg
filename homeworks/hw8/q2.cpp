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

// DSU 
int par[200000], rnk[200000];

int find(int x) {
  while (par[x] != x) x = par[x] = par[par[x]];
  return x;
}

bool uni(int a, int b) {
  a = find(a); b = find(b);
  if (a == b) return false;
  if (rnk[a] < rnk[b]) swap(a,b);
  par[b] = a;
  if (rnk[a] == rnk[b]) rnk[a]++;
  return true;
}

static void solve_one() {
  int n,m,k;
  cin >> n >> m >> k;

  struct Edge { int u,v; ll w;};
  vector<Edge> edges(m);

  ll max_ew = -1;
  ll min_ew = LLONG_MAX;

  forn(i,m) {
    cin >> edges[i].u >> edges[i].v >> edges[i].w;
    if (edges[i].w <= k) max_ew = max(max_ew, edges[i].w);
    else min_ew = min(min_ew, edges[i].w);
  }

  rep(i,1,n) {
    par[i] = i;
    rnk[i] = 0;
  }

  sort(all(edges), [&](const Edge& a, const Edge& b) {
      ll ca = max(0LL,a.w - k);
      ll cb = max(0LL,b.w-k);
      if (ca != cb) return ca < cb;
      return a.w > b.w;
  });

  ll total_excess = 0;
  bool has_ge = false;

  for(auto& [u,v,w] : edges) {
    if (uni(u,v)) {
      if (w > k) total_excess += w - k;
      if (w >= k) has_ge = true;
    }
  }

  if (has_ge) cout << total_excess << "\n";
  else {
    ll cost1 = k - max_ew;
    ll cost2 = (min_ew != LLONG_MAX) ? (min_ew - k) : LLONG_MAX;
    cout << min(cost1,cost2) << "\n";
  }

}

int main() {
    fast_io();

    // solve_one();
    

    int T; cin >> T;
    while (T--) solve_one();
    

    // int n;
    // while (cin >> n && n != 0){
    //  solve_one(n);
    // }

    return 0;
}

