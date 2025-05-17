#include <bits/stdc++.h>
using namespace std;

// Bubble Sort, Stable, O(n^2)
template <typename T, typename Compare = less<T>>
void bubble_sort(vector<T>& a, Compare cmp = Compare()) {
    int n = a.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = n - 1; j > i; j--) {
            if (cmp(a[j], a[j - 1])) {
                swap(a[j], a[j - 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
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

    bubble_sort(a);

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
