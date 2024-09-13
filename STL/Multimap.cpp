#include <bits/stdc++.h>
using namespace std;

void solve() {
    // Multimap is an associative container that contains a sorted set of keys & their values
    multimap<int, char> mp = {{1, 'x'}, {2, 'y'}, {3, 'z'}, {10, 'w'}, {10, 'v'}};
    multimap<int, char, greater<int>> mp2 = {{10, 'v'}, {10, 'w'}, {3, 'z'}, {2, 'y'}, {1, 'x'}};

    // begin, end, rbegin, rend
    // size, empty, clear

    // insert({key, value}), insert(initial_list), insert(it_begin, it_end), insert(pos, {key, value})
    // erase(key), erase(pos), erase(pos_begin, pos_end)
    // emplace(key, value), emplace_hint(pos, key, value)

    // insert(pos, {key, value}), emplace_hint(pos, key, value), erase(pos) -> O(1)
    // erase(key), count(key) -> O(log(n)+count(key))
 
    // mp.contains(key)
    // mp.merge(mp0), O(n*log(n))

    int cnt = mp.count(10);
    multimap<int, char>::iterator it = mp.find(10);
    cout << cnt << ' ' << it->first << ' ' << it->second << '\n';

    // lower_bound(key) -> The first element greater than or equal to key 
    // upper_bound(key) -> The first element greater than to key 
    multimap<int, char>::iterator lb = mp.lower_bound(3);
    multimap<int, char>::iterator ub = mp.upper_bound(3);
    cout << lb->first << ' ' << lb->second << '\n'; 
    cout << ub->first << ' ' << ub->second  << '\n';

    for (auto [key, value] : mp) {
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
