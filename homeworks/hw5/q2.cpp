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
  int n; cin >> n;
  vector<int> a(n);
  rdvec(a,n);

  vector<vector<int>> dp(n,vector<int>(n,0));
  forn(i,n) dp[i][i] = 1;

  rep(len,2,n) {
    forn(l,n-len+1) {
      int r = l + len - 1;

      dp[l][r] = 1 + dp[l+1][r];
      if (a[l] == a[l+1]) {
        dp[l][r] = min(dp[l][r], 1 + (l+2 <= r ? dp[l+2][r] : 0));
      }

      rep(k,l+2,r) {
        if (a[l] == a[k]) {
          int cost = dp[l+1][k-1] + (k+1 <= r ? dp[k+1][r] : 0);
          dp[l][r] = min(dp[l][r], cost);
        }
      }
    }
  }

  cout << dp[0][n-1] << "\n";
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

