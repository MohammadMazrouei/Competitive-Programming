#include <bits/stdc++.h>
using namespace std;

void solve() {
    // Set is an associative container that contains a sorted set of unique objects
    set<int> s = {1, 2, 3, 4, 5, 10};
    set<int, greater<int>> s2 = {10, 5, 4, 3, 2, 1};

    // begin, end, rbegin, rend
    // size, empty, clear

    // insert(key), insert(initial_list), insert(it_begin, it_end), insert(pos, key)
    // erase(key), erase(pos), erase(pos_begin, pos_end)
    // emplace(key), emplace_hint(pos, key)
 
    // s.contains(key)
    // s.merge(s0), O(n*log(n))

    int cnt = s.count(5);
    set<int>::iterator it = s.find(5);
    cout << cnt << ' ' << *it << '\n';

    // lower_bound(x) -> The first element greater than or equal to x
    // upper_bound(x) -> The first element greater than to x
    set<int>::iterator lb = s.lower_bound(5);
    set<int>::iterator up = s.upper_bound(5);
    cout << *lb << ' ' << *up << '\n';
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
