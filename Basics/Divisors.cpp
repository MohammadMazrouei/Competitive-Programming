#include <bits/stdc++.h>
using namespace std;

// Find Divisors, O(sqrt(n))
template <typename T>
vector<T> divisors(T n) {
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

    vector<int64_t> div = divisors(n);
    sort(div.begin(), div.end());
    cout << div.size() << '\n';
    for (auto d : div) {
        cout << d << " \n"[d == div.back()];
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
