#include <bits/stdc++.h>
using namespace std;

// Checks if x is odd or even
bool is_odd(int x) {
    return x & 1;
}

// Checks if kth bit of x is set
bool check_kth_bit(int x, int k) {
    return x >> k & 1;
}

// Returns the count of set bits
int count_set_bits(int x) {
    int res = 0;
    for (int k = 0; k < 32; k++) {
        res += x >> k & 1;
    }
    return res;
}

// Sets the kth bit of x
int set_kth_bit(int x, int k) {
    return x | (1 << k);
}

// Unsets the kth bit of x
int unset_kth_bit(int x, int k) {
    return x & (~(1 << k));
}

// Toggles the kth bit of x
int toggle_kth_bit(int x, int k) {
    return x ^ (1 << k);
}

// Checks if x is a power of 2
bool check_power_of_2(int x) {
    return count_set_bits(x) == 1;
}

// Prints the binary representation of x
void to_binary(int x) {
    for (int k = 31; k >= 0; k--) {
        cout << (x >> k & 1);
    }
    cout << '\n';
}

void solve() {
    int n;
    cin >> n;

    to_binary(n);

    // __builtin_popcountll, __builtin_clzll, __builtin_ctzll
    // Count set bits
    cout << __builtin_popcount(n) << '\n';
    // Count of leading zeros
    cout << __builtin_clz(n) << '\n';
    // Count of trailing zeros
    cout << __builtin_ctz(n) << '\n';
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
