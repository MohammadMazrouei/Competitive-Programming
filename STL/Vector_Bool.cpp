#include <bits/stdc++.h>
using namespace std;

/*
Store each bool as a single bit.
The bitfield representation necessitates extra bit manipulation.
Standard algorithms and functions that expect regular references may encounter 
issues with the proxy object, leading to unexpected behavior or compilation errors.
*/
void solve() {
    // --- Initialization ---
    vector<bool> v1(4),
                 v2(4, true), 
                 v3 = {false, true, false, true};
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
    // flip()

    // --- Hints ---
    // assign replacing a vector<bool> with new properties (size and elements). 
    // resize holding old data and expanding the new vector<bool> with new elements.
    // reserve change capacity of vector<bool>.

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
