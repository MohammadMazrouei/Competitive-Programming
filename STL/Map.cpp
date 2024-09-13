#include <bits/stdc++.h>
using namespace std;

void solve() {
    // Map is an associative container that contains a sorted set of unique keys & their values
    map<int, char> mp = {{1, 'x'}, {2, 'y'}, {3, 'z'}, {10, 'w'}};
    map<int, char, greater<int>> mp2 = {{10, 'w'}, {3, 'z'}, {2, 'y'}, {1, 'x'}};

    // begin, end, rbegin, rend
    // [], at
    // size, empty, clear

    // insert({key, value}), insert(initial_list), insert(it_begin, it_end), insert(pos, {key, value})
    // erase(key), erase(pos), erase(pos_begin, pos_end)
    // emplace(key, value), emplace_hint(pos, key, value)
    // insert_or_assign({key, value})

    // insert(pos, {key, value}), emplace_hint(pos, key, value), erase(pos) -> O(1)
 
    // mp.contains(key)
    // mp.merge(mp0), O(n*log(n))

    int cnt = mp.count(2);
    map<int, char>::iterator it = mp.find(2);
    cout << cnt << ' ' << it->first << ' ' << it->second << '\n';

    // lower_bound(key) -> The first element greater than or equal to key 
    // upper_bound(key) -> The first element greater than to key 
    map<int, char>::iterator lb = mp.lower_bound(3);
    map<int, char>::iterator ub = mp.upper_bound(3);
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
