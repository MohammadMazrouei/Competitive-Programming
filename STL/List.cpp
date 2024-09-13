#include <bits/stdc++.h>
using namespace std;

void solve() {
    list<int> l = {1, 2, 3, 4}, l2(10), l3(10, 1);

    // begin, end, rbegin, rend
    // front, back
    // size, empty, clear
    // push_back, push_front, pop_back, pop_front, emplace_back, emplace_front

    // insert(pos, data), insert(pos, n, data), insert(pos, initial_list), insert(pos, it_begin, it_end)
    // erase(pos), erase(pos_begin, pos_end)
    // emplace(pos, data)

    // remove(data), remove_if(const function<int(bool)> f)
    // sort, reverse, unique, merge(other_sorted_list)

    // Transfers(Not copy) elements from one list to another in O(1).
    // l.splice(pos, other_list), l.splice(pos, other_list, it_begin(), it_end())

    // Assign replacing a list with new properties (size and elements). 
    // Resize holding old data and expanding the new list with new elements.
    l.assign(4, 2);
    l.resize(10, 4);
    for (auto x : l) {
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
