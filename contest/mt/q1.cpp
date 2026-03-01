// Estimated Codeforces difficulty: ~800
#include <bits/stdc++.h>
using namespace std;

static inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

static void solve_one() {
    int a[3];
    for (int i = 0; i < 3; i++) cin >> a[i];
    
    if (a[0] <= a[1] && a[1] <= a[2]) { 
      cout << 0 << "\n"; 
      return; 
    }
    
    for (int i = 0; i < 3; i++)
        for (int j = i + 1; j < 3; j++) {
            swap(a[i], a[j]);
            if (a[0] <= a[1] && a[1] <= a[2]) { 
              cout << 1 << "\n"; 
              return; 
            }
            swap(a[i], a[j]);
        }
    cout << 2 << "\n";
}

int main() {
    fast_io();

    solve_one();

    return 0;
}

