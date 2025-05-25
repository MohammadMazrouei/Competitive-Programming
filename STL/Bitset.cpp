#include <bits/stdc++.h>
using namespace std;

void solve() {
    // --- Initialization ---
    bitset<20> bs1, 
               bs2(1234), 
               bs3("10101100");

    // --- Capacity ---
    // size()
    
    // --- Element accessa ---
    // [index], test(index)
    // count(), all(), any(), none()
    
    // --- Modifiers ---
    // set(), set(index)
    // reset(), reset(index)
    // flip(), flip(index)
    // &, |, ^, <<, >>, ~
    // &=, |=, ^=, <<=, >>=

    // --- Conversions ---
    // to_string()
    // to_ulong(), to_ullong()

    // --- Hints ---
    // _Find_first(), return index of the first set bit.
    // _Find_next(index), return index of the next set bit after index.

    cout << bs3 << '\n';
    cout << bs3._Find_first() << '\n';
    cout << bs3._Find_next(1) << ' ' << bs3._Find_next(2) << '\n';
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
