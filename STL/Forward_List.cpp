#include <bits/stdc++.h>
using namespace std;

void solve() {
    forward_list<int> l = {1, 2, 3, 4}, l2(10), l3(10, 1);

    // begin, end, before_begin
    // front
    // size, empty, clear
    // push_front, pop_front, emplace_front

    // insert_after(pos, data), insert_after(pos, n, data), insert_after(pos, initial_list), insert_after(pos, it_begin, it_end)
    // erase_after(pos), erase_after(pos_begin, pos_end)
    // emplace_after(pos, data)

    // remove(data), remove_if(function<int(bool)> &f)
    // sort, reverse, unique, merge(other_sorted_list)

    // Transfers(Not copy) elements from one list to another in O(1).
    // l.splice_after(pos, other_list), l.splice_after(pos, other_list, it_begin(), it_end())

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
