#include <bits/stdc++.h>
using namespace std;

// Multimap is an associative container that contains a sorted set of keys & their values.
void solve() {
    // --- Initialization ---
    multimap<int, char> mmp1 = {{1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}, {4, 'd'}};
    multimap<int, char, greater<int>> mmp2 = {{4, 'd'}, {4, 'd'}, {3, 'c'}, {2, 'b'}, {1, 'a'}};

    // --- Iterators ---
    // begin(), end()
    // rbegin(), rend()

    // --- Capacity ---
    // size(), empty()

    // --- Modifiers ---
    // insert({key, value}), insert(initial_list), insert(it_first, it_last),
    // insert(pos, {key, value}), emplace(args...), emplace_hint(pos, args...)
    // erase(key), erase(pos), erase(pos_first, pos_last)
    // merge(multimap) -> O(n*log(n))
    // clear()
 
    // --- Lookup ---
    // count(key), contains(key)
    // find(key)
    // lower_bound(key) -> The first element greater than or equal to key.
    // upper_bound(key) -> The first element greater than to key.
    multimap<int, char>::iterator lb = mmp1.lower_bound(2);
    multimap<int, char>::iterator ub = mmp1.upper_bound(2);
    cout << lb->first << ' ' << lb->second << '\n'; 
    cout << ub->first << ' ' << ub->second  << '\n';

    // --- Hints ---
    // insert(pos, {key, value}), emplace_hint(pos, args...), erase(pos)
    // O(1) if the insertion happens in the position just after or before pos, O(log(n)) otherwise.
    // erase(key), removes all occurrences of 'key', returns count of removed elements.
    // erase(key), count(key) -> O(log(n) + count(key))

    for (auto [key, value] : mmp1) {
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
