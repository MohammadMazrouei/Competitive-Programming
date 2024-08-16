#include <bits/stdc++.h>
using namespace std;

template <typename T> using pqg = priority_queue<T>;
template <typename T> using pql = priority_queue<T, vector<T>, greater<T>>;

template <typename T> bool cmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template <typename T> bool cmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define uid(a, b) uniform_int_distribution<int64_t>(a, b)(rng)

#ifdef DEBUG
#include "/home/mohammad/code/debug.h"
#else
#define dbg(...)
#define dbgarr(...)
#endif

void solve() {
        
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
