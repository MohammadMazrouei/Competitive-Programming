#include <bits/stdc++.h>
using namespace std;

// unordered_multiset is an associative container that contains a set of objects.
// Search, insertion, and removal have average O(1) and worst case O(n).
void solve() {
    // --- Initialization ---
    unordered_multiset<int> ums1 = {1, 2, 3, 4, 5, 10, 10};

    // --- Iterators ---
    // begin(), end()

    // --- Capacity ---
    // size(), empty()

    // --- Modifiers ---
    // insert(value), insert(initializer_list), insert(it_first, it_last),
    // insert(pos, value), emplace(args...), emplace_hint(pos, args...)
    // erase(value), erase(pos), erase(pos_first, pos_last)
    // merge(unordered_multiset)
    // clear()
 
    // --- Lookup ---
    // count(value), contains(value)
    // find(value)

    // --- Bucket interface ---
    // bucket_count()
    // bucket(value), bucket_size(index)
    // begin(index), end(index)

    // --- Hash policy ---
    // load_factor()
    // max_load_factor(), max_load_factor(f)
    // rehash(count), reserves at least the specified number of buckets and regenerates the hash table.
    // reserve(count), reserves space for at least the specified number of elements and regenerates the hash table.

    // --- Hints ---
    // erase(value), removes all occurrences of 'value', returns count of removed elements.
    // When using a custom class with an unordered_multiset, it's necessary
    // to defineboth a hash function and an equality comparison for that class.

    for (auto x : ums1) {
        cout << x << '\n';
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
