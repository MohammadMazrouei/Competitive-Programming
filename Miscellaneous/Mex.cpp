#include <bits/stdc++.h>
using namespace std;

// Minimal Excluded(MEX), O(n)
template <typename T>
int mex(const vector<T> &v) {
    int n = v.size();
    vector<bool> f(n + 1);
    for (int x : v) {
        if (x <= n) {
            f[x] = 1;
        }
    }
    int mex = 0;
    while (f[mex]) {
        mex++;
    }
    return mex;
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << mex(a) << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
