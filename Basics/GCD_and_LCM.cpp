#include <bits/stdc++.h>
using namespace std;

// Greatest Common Divisor, O(log(min(a, b)))
// gcd always be non-negative, gcd(*, 0) = 0
template <typename T>
T my_gcd(T a, T b) {
    a = abs(a), b = abs(b);
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

// Least Common Multiple, O(log(min(a, b)))
// lcm always be non-negative, lcm(*, 0) = 0
template <typename T>
T my_lcm(T a, T b) {
    if (a == 0 || b == 0) {
        return 0;
    }
    a = abs(a), b = abs(b);
    return a / my_gcd(a, b) * b;
}

void solve() {
    int64_t a, b;
    cin >> a >> b;

    int64_t g1 = gcd(a, b), l1 = lcm(a, b);
    int64_t g2 = my_gcd(a, b), l2 = my_lcm(a, b);

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
