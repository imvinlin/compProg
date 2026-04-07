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
  rdvec(a, n);

  vector<vector<int>> val(n, vector<int>(n, -1));
  vector<vector<int>> dp(n, vector<int>(n, 0));

  forn(i, n) {
    val[i][i] = a[i];
    dp[i][i] = 1;
  }

  rep(len, 2, n) {
    forn(i, n - len + 1) {
      int j = i + len - 1;
      dp[i][j] = len; 
      rep(k, i, j - 1) {
        if (val[i][k] != -1 && val[i][k] == val[k + 1][j])
          val[i][j] = val[i][k] + 1;
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
      }
      if (val[i][j] != -1) dp[i][j] = 1;
    }
  }

  cout << dp[0][n - 1] << "\n";
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

