#include <bits/stdc++.h>
using namespace std;

// multiset is an associative container that contains a sorted set of objects.
void solve() {
    // --- Initialization ---
    multiset<int> ms1 = {1, 2, 3, 4, 5, 10, 10};
    multiset<int, greater<int>> ms2 = {10, 10, 5, 4, 3, 2, 1};

    // --- Iterators ---
    // begin(), end()
    // rbegin(), rend()

    // --- Capacity ---
    // size(), empty()

    // --- Modifiers ---
    // insert(value), insert(initializer_list), insert(it_first, it_last),
    // insert(pos, value), emplace(args...), emplace_hint(pos, args...)
    // erase(value), erase(pos), erase(pos_first, pos_last)
    // merge(multiset) -> O(n*log(n))
    // clear()
 
    // --- Lookup ---
    // count(value), contains(value)
    // find(value)
    // lower_bound(value) -> The first element greater than or equal to value.
    // upper_bound(value) -> The first element greater than to value.
    multiset<int>::iterator lb = ms1.lower_bound(5);
    multiset<int>::iterator ub = ms1.upper_bound(5);
    cout << *lb << ' ' << *ub << '\n';

    // --- Hints ---
    // insert(pos, value), emplace_hint(pos, args...), erase(pos)
    // O(1) if the insertion happens in the position just after or before pos, O(log(n)) otherwise.
    // erase(value), removes all occurrences of 'value', returns count of removed elements.
    // erase(value), count(value) -> O(log(n) + count(value))
    // When using a custom class with a multiset, it's necessary to define a comparator for that class,
    // as the default comparison often relies on the less-than operator (<).

    for (auto x : ms1) {
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
