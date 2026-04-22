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

const int BITS = 30;

struct Trie {
    vector<array<int,2>> ch = {{0,0}};
    vector<int> cnt = {0};

    void update(int x, int delta) {
        int cur = 0;
        rforn(i, BITS) {
            int b = (x >> i) & 1;
            if (!ch[cur][b]) {
                ch.push_back({0,0});
                cnt.push_back(0);
                ch[cur][b] = (int)ch.size() - 1;
            }
            cur = ch[cur][b];
            cnt[cur] += delta;
        }
    }

    int query(int x) {
        int cur = 0, res = 0;
        rforn(i, BITS) {
            int b = (x >> i) & 1;
            int want = 1 - b;
            if (ch[cur][want] && cnt[ch[cur][want]] > 0) {
                res |= (1 << i);
                cur = ch[cur][want];
            } else {
                cur = ch[cur][b];
            }
        }
        return res;
    }
};

static void solve_one() {
    int q; cin >> q;
    Trie t;
    t.update(0, 1);
    forn(i, q) {
        char op; int x;
        cin >> op >> x;
        if (op == '+') t.update(x, 1);
        else if (op == '-') t.update(x, -1);
        else cout << t.query(x) << "\n";
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

