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

static void solve_one() {
  int n, m, c0, d0;
  cin >> n >> m >> c0 >> d0;

  vector<int> dp(n + 1, 0);

  forn(i, m) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int cnt = a / b;
    
    for (int k = 1; cnt > 0; k *= 2) {
      int take = min(k, cnt);
      cnt -= take;
      int w = take * c, v = take * d;
      rforn(j, n + 1) {
        if (j >= w)
          dp[j] = max(dp[j], dp[j - w] + v);
      }
    }
  }

  rep(j, c0, n) {
    dp[j] = max(dp[j], dp[j - c0] + d0);
  }

  cout << dp[n] << "\n";
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

