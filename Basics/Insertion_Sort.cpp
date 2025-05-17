#include <bits/stdc++.h>
using namespace std;

// Insertion Sort, Stable, O(n^2)
template <typename T, typename Compare = less<T>>
void insertion_sort(vector<T>& a, Compare cmp = Compare()) {
    int n = a.size();
    for (int i = 1; i < n; i++) {
        T x = a[i];
        int j = i - 1;
        while (j >= 0 && cmp(x, a[j])) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = x;
    }
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    insertion_sort(a);

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
