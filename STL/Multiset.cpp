#include <bits/stdc++.h>
using namespace std;

void solve() {
    // Multiset is an associative container that contains a sorted set of objects
    multiset<int> ms = {1, 2, 3, 4, 5, 5, 10};
    multiset<int, greater<int>> ms2 = {10, 5, 5, 4, 3, 2, 1};

    // begin, end, rbegin, rend
    // size, empty, clear

    // insert(key), insert(initial_list), insert(it_begin, it_end), insert(pos, key)
    // erase(key), erase(pos), erase(pos_begin, pos_end)
    // emplace(key), emplace_hint(pos, key)

    // insert(pos, key), emplace_hint(pos, key), erase(pos) -> O(1)
    // erase(key), count(key) -> O(log(n)+count(key))
 
    // ms.contains(key)
    // ms.merge(ms0), O(n*log(n))

    int cnt = ms.count(5);
    multiset<int>::iterator it = ms.find(5);
    cout << cnt << ' ' << *it << '\n';

    // lower_bound(x) -> The first element greater than or equal to x
    // upper_bound(x) -> The first element greater than to x
    multiset<int>::iterator lb = ms.lower_bound(5);
    multiset<int>::iterator ub = ms.upper_bound(5);
    cout << *lb << ' ' << *ub << '\n';

    for (auto x : ms) {
        cout << x << ' ';
    }
    cout << '\n';
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
