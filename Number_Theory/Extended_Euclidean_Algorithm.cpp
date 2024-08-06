#include <bits/stdc++.h>
using namespace std;

// Extended Euclidean Algorithm, O(log(min(a, b)))
int64_t exgcd(int64_t a, int64_t b, int64_t &x, int64_t &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int64_t x1, y1;
    int64_t d = exgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

void solve() {
    int64_t a, b;
    cin >> a >> b;

    int64_t x, y;
    int64_t g = exgcd(a, b, x, y);
    
    cout << g << ' ' << x << ' ' << y << '\n';
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
