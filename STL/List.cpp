#include <bits/stdc++.h>
using namespace std;

void solve() {
    // --- Initialization ---
    list<int> l1(4),
              l2(4, 1), 
              l3 = {1, 2, 3, 4};
    // assign(n, value)

    // --- Iterators ---
    // begin(), end()
    // rbegin(), rend()

    // --- Capacity ---
    // size(), empty()

    // --- Element accessa ---
    // front(), back()

    // --- Modifiers ---
    // push_front(value), push_back(value)
    // emplace_front(args...), emplace_back(args...)
    // insert(pos, value), insert(pos, n, value), insert(pos, initializer_list)
    // insert(pos, it_first, it_last), emplace(pos, args...)
    // pop_front(), pop_back()
    // erase(pos), erase(pos_first, pos_last)
    // resize(n, value), clear()

    // --- Operations ---
    // sort(), reverse(), unique(), merge(sorted_list)
    // Remove all elements satisfying criteria.
    // remove(value), remove_if(UnaryPred)
    // Transfers(not copy) elements from another list to this list.
    // splice(pos, list), splice(pos, list, it_first, it_last)

    // --- Hints ---
    // assign replacing a list with new properties (size and elements). 
    // resize holding old data and expanding the new list with new elements.

    for (auto x : l1) {
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
