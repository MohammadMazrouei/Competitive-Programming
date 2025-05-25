#include <bits/stdc++.h>
using namespace std;

// Map is an associative container that contains a sorted set of unique keys & their values.
void solve() {
    // --- Initialization ---
    map<int, char> mp1 = {{1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}};
    map<int, char, greater<int>> mp2 = {{4, 'd'}, {3, 'c'}, {2, 'b'}, {1, 'a'}};

    // --- Iterators ---
    // begin(), end()
    // rbegin(), rend()

    // --- Capacity ---
    // size(), empty()

    // --- Element accessa ---
    // [index], at(index)

    // --- Modifiers ---
    // insert({key, value}), insert(initial_list), insert(it_first, it_last),
    // insert(pos, {key, value}), emplace(args...), emplace_hint(pos, args...)
    // insert_or_assign({key, value})
    // erase(key), erase(pos), erase(pos_first, pos_last)
    // merge(map) -> O(n*log(n))
    // clear()
 
    // --- Lookup ---
    // count(key), contains(key)
    // find(key)
    // lower_bound(key) -> The first element greater than or equal to key.
    // upper_bound(key) -> The first element greater than to key.
    map<int, char>::iterator lb = mp1.lower_bound(2);
    map<int, char>::iterator ub = mp1.upper_bound(2);
    cout << lb->first << ' ' << lb->second << '\n'; 
    cout << ub->first << ' ' << ub->second  << '\n';

    // --- Hints ---
    // insert(pos, {key, value}), emplace_hint(pos, args...), erase(pos)
    // O(1) if the insertion happens in the position just after or before pos, O(log(n)) otherwise.

    for (auto [key, value] : mp1) {
        cout << key << ' ' << value << '\n';;
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
