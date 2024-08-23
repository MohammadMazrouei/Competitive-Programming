#include <bits/stdc++.h>
using namespace std;

void solve() {
    vector<int> v = {1, 2, 3, 4}, v2(10), v3(10, 1);

    // begin, end, rbegin, rend
    // front, back, [], at
    // size, empty, clear
    // push_back, pop_back, emplace_back

    // insert(pos, data), insert(pos, n, data), insert(pos, it_begin, it_end)
    // erase(pos), erase(pos_begin, pos_end)
    // emplace(pos, data)

    // Assign replacing a vector with new properties (size and elements). 
    // Resize holding old data and expanding the new vector with new elements.
    // Reserve change capacity of vector.
    v.assign(4, 2);
    v.resize(10, 4);
    v.reserve(100);
    for (auto x : v) {
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
