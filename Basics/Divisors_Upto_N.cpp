#include <bits/stdc++.h>
using namespace std;

// Find All Divisors Upto n, O(n*log(n))
void solve() {
    int n;
    cin >> n;

    vector<vector<int>> div(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            div[j].push_back(i);
        }
    }

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
