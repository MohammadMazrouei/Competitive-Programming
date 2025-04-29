#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, q;;
    cin >> n >> q;

    vector a(n, vector(n, vector<int>(n)));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                cin >> a[i][j][k];
            }
        }
    }

    vector p(n + 1, vector(n + 1, vector<int64_t>(n + 1)));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                p[i][j][k] 
                    = p[i - 1][j][k] + p[i][j - 1][k] + p[i][j][k - 1] 
                    - p[i - 1][j - 1][k] - p[i - 1][j][k - 1] - p[i][j - 1][k - 1] 
                    + p[i - 1][j - 1][k - 1] 
                    + a[i - 1][j - 1][k - 1];
            }
        }
    }

    while (q--) {
        int l1, r1, l2, r2, l3, r3;
        cin >> l1 >> r1 >> l2 >> r2 >> l3 >> r3;
        l1--, l2--, l3--;

        int64_t ans 
            = p[r1][r2][r3] 
            - p[l1][r2][r3] - p[r1][l2][r3] - p[r1][r2][l3] 
            + p[l1][l2][r3] + p[l1][r2][l3] + p[r1][l2][l3] 
            - p[l1][l2][l3];
        cout << ans << '\n';
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
