#include <bits/stdc++.h>
using namespace std;

using ll = long long;
static const ll INF = (1LL << 62);

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
  int n,m,k;
  cin >> n >> m >> k;

  vector<vector<pair<int,ll>>> adj(n+1);
  forn(i,m) {
    int u,v;
    ll x;
    cin >> u >> v >> x;
    adj[u].push_back({v,x});
    adj[v].push_back({u,x});
  }
  
  vector<ll> min_train(n+1,INF);
  vector<int> total_train(n+1,0);

  forn(i,k) {
    int s;
    ll y;
    cin >> s >> y;
    total_train[s]++;
    min_train[s] = min(min_train[s],y);
  }

  vector<ll> dist(n+1,INF);
  vector<int> road(n+1,0);
  priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;

  dist[1] = 0;
  pq.push({0,1});
  rep(s,2,n) {
    if (min_train[s] < INF) {
      dist[s] = min_train[s];
      pq.push({min_train[s],s});
    }
  }

  while (!pq.empty()) {
    auto [d,u] = pq.top();
    pq.pop();
    if (d > dist[u]) continue;

    for (auto [v,w] : adj[u]) {
      ll nd = d + w;
      if (nd < dist[v]) {
        dist[v] = nd;
        road[v] = 1;
        pq.push({nd,v});
      } else if (nd == dist[v]) {
        road[v]++;
      }
    }
  }

  int res = 0;
  rep(s,2,n) {
    if (total_train[s] == 0) continue;

    if (dist[s] < min_train[s]) {
      res += total_train[s];
    } else {
      if (road[s] > 0) {
        res += total_train[s];
      } else {
        res += total_train[s] - 1;
      }
    }
  }

  cout << res;


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

