#include <bits/stdc++.h>
using namespace std;

// Heap Sort, Not Stable, O(n*log(n))
template <typename T>
void heapify(vector<T> &a, int n, int i) {
    int largest = i;
    int left = 2 * i + 1, right = 2 * i + 2;
  
    if (left < n && a[left] > a[largest]) {
      largest = left;
    }
    if (right < n && a[right] > a[largest]) {
      largest = right;
    }
  
    if (largest != i) {
      swap(a[i], a[largest]);
      heapify(a, n, largest);
    }
  }
  
template <typename T>
void heap_sort(vector<T> &a) {
    int n = a.size();
    // Build Max Heap
    for (int i = n / 2 - 1; i >= 0; i--) {
      heapify(a, n, i);
    }
    // Heap Sort
    for (int i = n - 1; i >= 0; i--) {
      swap(a[0], a[i]);
      heapify(a, i, 0);
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
