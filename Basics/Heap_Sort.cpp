#include <bits/stdc++.h>
using namespace std;

// Heap Sort, Not Stable, O(n*log(n))
template <typename T, typename Compare>
void heapify(vector<T>& a, int n, int i, Compare cmp) {
    int extreme = i;
    int left = 2 * i + 1, right = 2 * i + 2;
  
    if (left < n && cmp(a[extreme], a[left])) {
        extreme = left;
    }
    if (right < n && cmp(a[extreme], a[right])) {
        extreme = right;
    }
  
    if (extreme != i) {
        swap(a[extreme], a[i]);
        heapify(a, n, extreme, cmp);
    }
}
  
template <typename T, typename Compare = less<T>>
void heap_sort(vector<T>& a, Compare cmp = Compare()) {
    int n = a.size();
    // Build Heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(a, n, i, cmp);
    }
    // Heap Sort
    for (int i = n - 1; i >= 0; i--) {
        swap(a[0], a[i]);
        heapify(a, i, 0, cmp);
    }
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    heap_sort(a);

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
