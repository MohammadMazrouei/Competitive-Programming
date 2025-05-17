#include <bits/stdc++.h>
using namespace std;

// Selection Sort, Not Stable, O(n^2)
template <typename T, typename Compare = less<T>>
void selection_sort(vector<T>& a, Compare cmp = Compare()) {
    int n = a.size();
    for (int i = 0; i < n; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (cmp(a[j], a[min_index])) {
                min_index = j;
            }
        }
        if (i != min_index) {
            swap(a[i], a[min_index]);
        }
    }
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    selection_sort(a);

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
