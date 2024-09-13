#include <bits/stdc++.h>
using namespace std;

void solve() {
    // Store each bool as a single bit
    vector<bool> v = {true, false, true, false}, v2(10), v3(10, true);

    // begin, end, rbegin, rend
    // front, back, [], at
    // size, empty, clear
    // push_back, pop_back, emplace_back

    // insert(pos, data), insert(pos, n, data), insert(pos, initial_list), insert(pos, it_begin, it_end)
    // erase(pos), erase(pos_begin, pos_end)
    // emplace(pos, data)

    // flip() -> filp all bits

    // Assign replacing a vector<bool> with new properties (size and elements). 
    // Resize holding old data and expanding the new vector<bool> with new elements.
    // Reserve change capacity of vector<bool>.
    v.assign(4, true);
    v.resize(10, false);
    v.reserve(100);
    for (auto x : v) {
        cout << x;
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
