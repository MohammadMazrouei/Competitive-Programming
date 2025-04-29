#include <bits/stdc++.h>
using namespace std;

// Counting Sort, Stable, O(n + M)
template <typename T>
void counting_sort(vector<T> &a) {
    static_assert(is_integral_v<T> && is_signed_v<T>,
                  "counting_sort requires signed integral type");

    int n = a.size();
    int M = *max_element(a.begin(), a.end());
    vector<int> cnt(M + 1);

    for (int i = 0; i < n; i++) {
        cnt[a[i]]++;
    }
    for (int i = 1; i <= M; i++) {
        cnt[i] += cnt[i - 1];
    }
    vector<T> tmp = a;
    for (int i = n - 1; i >= 0; i--) {
        a[--cnt[tmp[i]]] = tmp[i];
    }
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    counting_sort(a);

    for (int i = 0; i < n; i++) {
        cout << a[i] << " \n"[i == n - 1];
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
