#include <bits/stdc++.h>
using namespace std;

void solve() {
    vector<int> v = {1, 2, 3, 4}, v2(10), v3(10, 1);

    // begin, end, rbegin, rend
    // front, back, [], at
    // size, empty, clear
    // push_back, pop_back, emplace_back

    // insert(it, data), insert(it, n, data), insert(it, it_begin, it_end)
    // erase(it), erase(it_begin, it_end)
    // emplace

    // Assign replacing a vector with new properties (size and elements). 
    // Resize holding old data and expanding the new vector with new elements.
    v.assign(4, 2);
    v.resize(10, 4);
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
