#include <bits/stdc++.h>
using namespace std;

// Quick Sort, Not Stable, O(n^2)
template <typename T, typename Compare>
int partition(vector<T>& a, int l, int r, Compare cmp) {
    //mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    //swap(a[rng() % (r - l) + l], a[r]);
    T pivot = a[r];    

    int i = l;
    for (int j = l; j < r; j++) {
        if (cmp(a[j], pivot)) {
            swap(a[i++], a[j]);
        }
    }
    swap(a[i], a[r]);
    return i;
}

template <typename T, typename Compare>
void quick_sort(vector<T>& a, int l, int r, Compare cmp) {
    if (l >= r) {
        return;
    }
    int pi = partition(a, l, r, cmp);
    quick_sort(a, l, pi - 1, cmp);
    quick_sort(a, pi + 1, r, cmp);
}

template <typename T, typename Compare = less<T>>
void quick_sort(vector<T>& a, Compare cmp = Compare()) {
    quick_sort(a, 0, a.size() - 1, cmp);
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    quick_sort(a);

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
