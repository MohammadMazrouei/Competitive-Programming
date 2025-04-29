#include <bits/stdc++.h>
using namespace std;

// Find divisors of n, O(sqrt(n))
template <typename T>
vector<T> divisors(const T n) {
    vector<T> d;
    for (T i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            d.push_back(i);
            if (i * i != n) {
                d.push_back(n / i);
            }
        }
    }
    return d;
}

void solve() {
    int64_t n;
    cin >> n;

    vector<int64_t> divs = divisors(n);
    sort(divs.begin(), divs.end());
    cout << divs.size() << '\n';
    for (auto d : divs) {
        cout << d << " \n"[d == divs.back()];
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
