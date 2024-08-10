#include <bits/stdc++.h>
using namespace std;

// Binary Exponentiation, O(log(b))
template <typename T>
T power(T a, int64_t b){
    assert(b >= 0);
    T res {1};
    while (b) {
        if (b & 1) {
            res *= a;
        }
        a *= a;
        b >>= 1;
    }
    return res;
}

void solve() {
    int64_t a, b;
    cin >> a >> b;

    cout << power(a, b) << '\n';
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
