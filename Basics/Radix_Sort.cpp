#include <bits/stdc++.h>
using namespace std;

// Radix Sort, Stable, O(n * log(MAX))
template <typename T>
void counting_sort(vector<T> &a, int n, T place, T base) {
    vector<int> cnt(base);

    for (int i = 0; i < n; i++) {
        cnt[(a[i] / place) % base]++;
    }
    for (int i = 1; i < base; i++) {
        cnt[i] += cnt[i - 1];
    }
    vector<T> tmp = a;
    for (int i = n - 1; i >= 0; i--) {
        a[cnt[(tmp[i] / place) % base] - 1] = tmp[i];
        cnt[(tmp[i] / place) % base]--;
    }
}

template <typename T>
void radix_sort(vector<T> &a, T base = 10) {
    int n = a.size();
    T mx = *max_element(a.begin(), a.end());
    for (T place = 1; mx / place > 0; place *= base) {
        counting_sort(a, n, place, base);
    }
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    radix_sort(a);

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
