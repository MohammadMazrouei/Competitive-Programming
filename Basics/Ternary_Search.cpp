#include <bits/stdc++.h>
using namespace std;

void solve() {
    // Minimum of Unimodal Function f, O(log(n))
    auto ternary_search1 = [&](int low, int high, const function<int(const int)> &f) -> int {
        int lo = low - 1, hi = high + 1;
        while (hi - lo > 1) {
            int mid = lo + (hi - lo) / 2;
            if (f(mid) < f(mid + 1)) {
                hi = mid;
            }
            else {
                lo = mid;
            }
        }
        return hi;
    };

    // Maximum of Unimodal Function f, O(log(n))
    auto ternary_search2 = [&](int low, int high, const function<int(const int)> &f) -> int {
        int lo = low - 1, hi = high + 1;
        while (hi - lo > 1) {
            int mid = lo + (hi - lo) / 2;
            if (f(mid) < f(mid + 1)) {
                lo = mid;
            }
            else {
                hi = mid;
            }
        }
        return lo + 1;
    };

    // Real Ternary Search for Find Max(f), O(log(n / eps))
    const double eps = 1e-9;
    auto ternary_search = [&](double low, double high, const function<double(const double)> &f) -> double {
        double lo = low, hi = high;
        while (hi - lo > eps) {
            double m1 = lo + (hi - lo) / 3;
            double m2 = hi - (hi - lo) / 3;
            if (f(m1) <= f(m2)) {
                lo = m1;
            }
            else {
                hi = m2;
            }
        }
        return lo;
    };

    cout << ternary_search1(0, 100, [&](int x) { return abs(x - 10); }) << '\n';  // max(|x - 10|) = f(10)
    cout << ternary_search2(0, 100, [&](int x) { return -abs(x - 10); }) << '\n'; // min(-|x - 10|) = f(10)

    cout << fixed << setprecision(9);
    cout << ternary_search(0, 100, [&](double x) { return -2 * (x * x) + 10 * x + 3; }) << '\n'; // max(-2x^2 + 10x + 3) = f(2.5)
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
