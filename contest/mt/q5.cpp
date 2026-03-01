#include <bits/stdc++.h>
using namespace std;

static inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

static void solve_one() {
  int n,k; 
  cin >> n >> k;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  // vector<long long> b(k);
  
  int add = 0;
  for (int i = 0; i < k; i++) {
    int val; cin >> val;
    if (val > 0) add += val;
  }
  
  // kadane
  long long cur = 0, best1 = LLONG_MIN;
  for (int i = 0; i < n; i++) {
    cur = max(cur+a[i],(long long)a[i]);
    best1 = max(best1,cur);
  }

  // add best to front
  cur = add;
  long long best2 = LLONG_MIN;
  for (int i = 0; i < n; i++){
    cur = max(cur+a[i],(long long)a[i]);
    best2 = max(best2,cur);
  }

  // add best to back
  cur = 0;
  long long best3 = LLONG_MIN;
  for (int i = 0; i < n; i++){
    cur = max(cur+a[i],(long long)a[i]);
    best3 = max(best3,cur);
  }
  cur += add;
  best3 = max(best3,cur);

  cout << max(best1,max(best2,max(add,best3)));
  
}

int main() {
    fast_io();

    solve_one();
    

    // int T; cin >> T;
    // while (T--) solve_one();

    return 0;
}

