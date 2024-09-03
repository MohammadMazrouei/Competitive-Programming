#include <bits/stdc++.h>
using namespace std;

// Greatest Common Divisor, O(log(min(a, b)))
template <typename T>
T _gcd(T a, T b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

// Least Common Multiple, O(log(min(a, b)))
template <typename T>
T _lcm(T a, T b) {
    return a / _gcd(a, b) * b;
}

void solve() {
    int64_t a, b;
    cin >> a >> b;

    int64_t g1 = _gcd(a, b), l1 = _lcm(a, b);
    int64_t g2 = gcd(a, b), l2 = lcm(a, b);

    cout << g1 << ' ' << l1 << '\n';
    cout << g2 << ' ' << l2 << '\n';
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
