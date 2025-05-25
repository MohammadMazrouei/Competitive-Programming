#include <bits/stdc++.h>
using namespace std;

void solve() {
    // --- Initialization ---
    forward_list<int> fl1(4),
                      fl2(4, 1), 
                      fl3 = {1, 2, 3, 4};
    // assign(n, value)

    // --- Iterators ---
    // begin(), end()
    // before_begin()

    // --- Capacity ---
    // empty()

    // --- Element accessa ---
    // front()

    // --- Modifiers ---
    // push_front(value), emplace_front(args...)
    // insert_after(pos, value), insert_after(pos, n, value), insert_after(pos, initial_list)
    // insert_after(pos, it_first, it_last), emplace_after(pos, args...)
    // pop_front()
    // erase_after(pos), erase_after(pos_first, pos_last)
    // resize(n, value), clear()

    // --- Operations ---
    // sort(), reverse(), unique(), merge(sorted_forward_list)
    // Remove all elements satisfying criteria.
    // remove(value), remove_if(UnaryPred)
    // Transfers(not copy) elements from another forward_list to this forward_list.
    // splice_after(pos, forward_list), splice_after(pos, forward_list, it_first, it_last)

    // --- Hints ---
    // assign replacing a forward_list with new properties (size and elements). 
    // resize holding old data and expanding the new forward_list with new elements.

    for (auto x : fl1) {
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
