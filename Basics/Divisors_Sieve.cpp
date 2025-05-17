#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    // Find sum of divisor counts up to n, O(sqrt(n))
    auto sum_of_divisor_counts = [](const int64_t x) -> int64_t {
        int64_t res = 0, i = 1;
        for (; i * i <= x; i++) {
            res += x / i;
        }
        res = 2 * res - (i - 1) * (i - 1);
        return res;
    };

    // Find divisors of numbers up to n, O(n*log(n))
    vector<vector<int>> divs(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            divs[j].push_back(i);
        }
    }

    cout << sum_of_divisor_counts(n) << '\n';
    for (int i = 1; i <= n; i++) { 
        cout << '#' << i << '\n';
        for (auto d : divs[i]) {
            cout << d << " \n"[d == divs[i].back()];
        }
    }
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
