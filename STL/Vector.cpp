#include <bits/stdc++.h>
using namespace std;

void solve() {
    // --- Initialization ---
    vector<int> v1(4),
                v2(4, 1), 
                v3 = {1, 2, 3, 4};
    // assign(n, value)

    // --- Iterators ---
    // begin(), end()
    // rbegin(), rend()

    // --- Capacity ---
    // size(), empty()
    // reserve(n), capacity()

    // --- Element accessa ---
    // front(), back()
    // [index], at(index)

    // --- Modifiers ---
    // push_back(value), emplace_back(args...)
    // insert(pos, value), insert(pos, n, value), insert(pos, initializer_list)
    // insert(pos, it_first, it_last), emplace(pos, args...)
    // pop_back()
    // erase(pos), erase(pos_first, pos_last)
    // resize(n, value), clear()

    // --- Hints ---
    // assign replacing a vector with new properties (size and elements). 
    // resize holding old data and expanding the new vector with new elements.
    // reserve change capacity of vector.

    for (auto x : v1) {
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
