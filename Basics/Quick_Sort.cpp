#include <bits/stdc++.h>
using namespace std;

// Quick Sort, Not Stable, O(n^2)
template <typename T>
int partition(vector<T> &a, int l, int r) {
    //mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    //swap(a[rng() % (r - l) + l], a[r]);
    T pivot = a[r];    

    int i = l;
    for (int j = l; j < r; j++) {
        if (a[j] <= pivot) {
            swap(a[i++], a[j]);
        }
    }
    swap(a[i], a[r]);
    return i;
}


template <typename T>
void quick_sort(vector<T> &a, int l, int r) {
    if (l >= r) {
        return;
    }
    int pi = partition(a, l, r);
    quick_sort(a, l, pi - 1);
    quick_sort(a, pi + 1, r);
}

template <typename T>
void quick_sort(vector<T> &a) {
    if (a.size() == 0) {
        return;
    }
    quick_sort(a, 0, a.size() - 1);
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
