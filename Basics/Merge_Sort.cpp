#include <bits/stdc++.h>
using namespace std;

// Merge Sort, Stable, O(n*log(n))
template <typename T, typename Compare>
void merge(vector<T>& a, int l, int r, int m, Compare cmp) {
    vector<T> left(a.begin() + l, a.begin() + m + 1);
    vector<T> right(a.begin() + m + 1, a.begin() + r + 1);
    int n1 = left.size(), n2 = right.size();

    int i = 0, j = 0, k = l;
    while (i < n1 || j < n2) {
        if (i < n1 && (j >= n2 || cmp(left[i], right[j]))) {
            a[k++] = left[i++];
        } else {
            a[k++] = right[j++];
        }
    }
}

template <typename T, typename Compare>
void merge_sort(vector<T>& a, int l, int r, Compare cmp) {
    if (l >= r) {
        return;
    }
    int m = l + (r - l) / 2;
    merge_sort(a, l, m, cmp);
    merge_sort(a, m + 1, r, cmp);
    merge(a, l, r, m, cmp);
}

template <typename T, typename Compare = less<T>>
void merge_sort(vector<T>& a, Compare cmp = Compare()) {
    merge_sort(a, 0, a.size() - 1, cmp);
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    merge_sort(a);

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
