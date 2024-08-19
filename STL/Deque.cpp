#include <bits/stdc++.h>
using namespace std;

void solve() {
    deque<int> dq = {1, 2, 3, 4}, dq2(10), dq3(10, 1);

    // begin, end, rbegin, rend
    // front, back, [], at
    // size, empty, clear
    // push_back, push_front, pop_back, pop_front, emplace_back, emplace_front

    // insert(pos, data), insert(pos, n, data), insert(pos, it_begin, it_end)
    // erase(pos), erase(pos_begin, pos_end)
    // emplace

    // Assign replacing a vector with new properties (size and elements). 
    // Resize holding old data and expanding the new vector with new elements.
    dq.assign(4, 2);
    dq.resize(10, 4);
    for (auto x : dq) {
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
