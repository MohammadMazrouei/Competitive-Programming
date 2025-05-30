#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    // Highest x satisfy f(x), O(log(n))
    auto binary_search1 = [](int low, int high, const function<bool(const int)>& f) -> int {
        int lo = low - 1, hi = high + 1;
        while (hi - lo > 1) {
            int mid = lo + (hi - lo) / 2;
            if (f(mid)) {
                lo = mid;
            } else {
                hi = mid;
            }
        }
        return lo;
    };

    // Lowest x satisfy f(x), O(log(n))
    auto binary_search2 = [](int low, int high, const function<bool(const int)>& f) -> int {
        int lo = low - 1, hi = high + 1;
        while (hi - lo > 1) {
            int mid = lo + (hi - lo) / 2;
            if (f(mid)) {
                hi = mid;
            } else {
                lo = mid;
            }
        }
        return hi;
    };

    // Real value binary search, O(log(n / eps))
    auto binary_search = [](double low, double high, const function<bool(const double)>& f) -> double {
        const double eps = 1e-9;
        double lo = low, hi = high;
        while (hi - lo > eps) {
            double mid = lo + (hi - lo) / 2;
            if (f(mid)) {
                lo = mid;
            } else {
                hi = mid;
            }
        }
        return lo;
    };

    // Calculate floor sqrt & ceil sqrt
    cout << binary_search1(0, n, [&n](int x) { return (int64_t)x * x <= n; }) << '\n';
    cout << binary_search2(0, n, [&n](int x) { return (int64_t)x * x >= n; }) << '\n';

    cout << fixed << setprecision(9);
    cout << binary_search(0, n, [&n](double x) { return x * x <= n; }) << '\n';
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
