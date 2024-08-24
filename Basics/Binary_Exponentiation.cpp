#include <bits/stdc++.h>
using namespace std;

// Binary Exponentiation, O(log(b))
template <typename T>
T power(T a, int64_t b, int64_t m){
    assert(b >= 0);
    T res {1};
    while (b) {
        if (b & 1) {
            res = res * a % m;
        }
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void solve() {
    int64_t a, b, p;
    cin >> a >> b >> p;

    cout << power(a, b, p) << '\n';
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
