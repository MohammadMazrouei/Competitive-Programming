#include <bits/stdc++.h>
using namespace std;

/*
 * Input Iterators
 *     (++, *, ->, ==, !=)
 * Output Iterators
 *     (++, *)
 * Forward Iterators
 *     (++, *, ->, ==, !=)
 *     forward_list
 * Bidirectional Iteartors
 *     (++, --, *, ->, ==, !=)
 *     set, multiset, map, multimap, list
 * Random-Access Iterators
 *     (++, --, *, ->, [], +, -, <, <=, >, >=, ==, !=)
 *     array, vector, deque
 */
void solve() {
    vector<int> v = {1, 2, 3, 4, 5, 6};

    vector<int>::iterator it_begin = v.begin();
    vector<int>::iterator it_end = v.end();
    vector<int>::reverse_iterator it_rbegin = v.rbegin();
    vector<int>::reverse_iterator it_rend = v.rend();

    // Random-Access -> O(1), Bidirectional -> O(n), (distance, next, prev, advance)
    cout << distance(it_begin, it_end) << '\n';
    cout << distance(it_end, it_begin) << '\n';

    cout << *next(it_begin, 2) << '\n';
    cout << *prev(it_end, 2) << '\n';
    cout << *next(it_rbegin) << '\n';
    cout << *prev(it_rend) << '\n';

    advance(it_begin, 4);
    cout << *it_begin << '\n';
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
