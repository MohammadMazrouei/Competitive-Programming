#include <bits/stdc++.h>
using namespace std;

// unordered_multimap is an associative container that contains a set of keys & their values.
// Search, insertion, and removal have average O(1) and worst case O(n).
void solve() {
    // --- Initialization ---
    unordered_multimap<int, char> ummp1 = {{1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}, {4, 'd'}};

    // --- Iterators ---
    // begin(), end()

    // --- Capacity ---
    // size(), empty()

    // --- Modifiers ---
    // insert({key, value}), insert(initializer_list), insert(it_first, it_last),
    // insert(pos, {key, value}), emplace(args...), emplace_hint(pos, args...)
    // erase(key), erase(pos), erase(pos_first, pos_last)
    // merge(unordered_multimap)
    // clear()
 
    // --- Lookup ---
    // count(key), contains(key)
    // find(key)

    // --- Bucket interface ---
    // bucket_count()
    // bucket(key), bucket_size(index)
    // begin(index), end(index)

    // --- Hash policy ---
    // load_factor()
    // max_load_factor(), max_load_factor(f)
    // rehash(count), reserves at least the specified number of buckets and regenerates the hash table.
    // reserve(count), reserves space for at least the specified number of elements and regenerates the hash table.

    // --- Hints ---
    // erase(key), removes all occurrences of 'key', returns count of removed elements.
    // When using a custom class with an unordered_multimap, it's necessary
    // to defineboth a hash function and an equality comparison for that class.

    for (auto [key, value] : ummp1) {
        cout << key << ' ' << value << '\n';
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
