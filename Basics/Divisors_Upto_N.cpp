#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    // Find All Divisors Upto n, O(n*log(n))
    vector<vector<int>> div(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            div[j].push_back(i);
        }
    }
    
    // Find Number of Divisors Upto n, O(sqrt(n))
    auto number_of_divisors = [&](int64_t x) -> int64_t {
        int64_t res = 0, i = 1;
        for (; i * i <= x; i++) {
            res += x / i;
        }
        res = 2 * res - (i - 1) * (i - 1);
        return res;
    };

    cout << number_of_divisors(n) << '\n';
    for (int i = 1; i <= n; i++) { 
        cout << '#' << i << '\n';
        for (auto d : div[i]) {
            cout << d << " \n"[d == div[i].back()];
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
