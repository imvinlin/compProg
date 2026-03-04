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
  int n,k; 
  cin >> n >> k;
  vector<int> a(n);
  rdvec(a,n);

  vector<vector<char>> dp(k+1, vector<char>(k+1,0));
  dp[0][0] = 1;

  for (int c : a) {
    vector<vector<char>> ndp = dp;

    rep(i,0,k) {
      rep(j,0,k) {
        if (!dp[i][j]) continue;

        if (i + c <= k) {
          ndp[i+c][j] = 1;

          if (j+c<=k) ndp[i+c][j+c] = 1;
        }
      }
    }
    dp.swap(ndp);
  }

  vector<int> res;
  rep(i,0,k) if (dp[k][i]) res.push_back(i);
  
  int m = (int)res.size();
  cout << m << "\n";
  forn(i,m) cout << ((i)?" ":"") << res[i];
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

