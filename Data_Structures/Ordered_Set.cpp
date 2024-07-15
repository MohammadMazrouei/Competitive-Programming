#include <bits/stdc++.h>
using namespace std;

// Ordered Set & Ordered Map
// s.order_of_key(k) -> number of elements less than k 
// *s.find_by_order(index) -> s[index]
#include <ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T, typename R> 
using ordered_map = tree<T, R, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
    int n;
    cin >> n;

    ordered_set<int> s;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        s.insert(v);
    }
    cout << *s.find_by_order(0) << '\n';
    cout << s.order_of_key(2) << '\n';

    ordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int k, v;
        cin >> k >> v;
        mp[k] = v;
    }
    cout << mp.find_by_order(0)->second << endl;
    cout << mp.order_of_key(2) << endl;
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
