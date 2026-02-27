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

struct Gate { char op; ll x; };
static void solve_one() {
  int n; cin >> n;
  vector<pair<Gate,Gate>> g(n);
  forn(i,n) {
    char op1,op2;
    ll x1,x2;

    cin >> op1 >> x1 >> op2 >> x2;
    g[i] = { Gate{op1,x1}, Gate{op2,x2} };
  }
  
  ll wl = 1, wr = 1, c = 0; // weight of left, weight of right, constant
  rforn(i,n) {
    ll ml = 0, mr = 0, add = 0; // multiply left, multiply right, add

    if (g[i].first.op == 'x') ml = g[i].first.x - 1;
    else add += g[i].first.x;

    if (g[i].second.op == 'x') mr = g[i].second.x - 1;
    else add += g[i].second.x;

    ll best = max(wl,wr);

    // previous will all move to the gate that is best
    c += best * add;
    wl += best * ml;
    wr += best * mr;
  }
    cout << (wr+wl+c) << "\n";
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

