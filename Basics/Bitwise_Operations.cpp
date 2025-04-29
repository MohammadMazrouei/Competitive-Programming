#include <bits/stdc++.h>
using namespace std;

// Return the kth bit of x
int kth_bit(int x, int k) {
    return x >> k & 1;
}

// Set the kth bit of x
int set_kth_bit(int x, int k) {
    return x | (1 << k);
}

// Unset the kth bit of x
int unset_kth_bit(int x, int k) {
    return x & (~(1 << k));
}

// Toggle the kth bit of x
int toggle_kth_bit(int x, int k) {
    return x ^ (1 << k);
}

// Return the lowest set bit of x
int lowest_set_bit(int x) {
    return x & -x;
}

// Unset the lowest set bit of x
int unset_lowest_set_bit(int x) {
    return x & (x - 1);
}

// Check x is odd
bool is_odd(int x) {
    return x & 1;
}

// Check x is a power of 2
bool check_power_of_2(int x) {
    return __popcount(x) == 1;
}

// Print the binary representation of x
void print_binary(int x) {
    for (int k = 31; k >= 0; k--) {
        cout << (x >> k & 1);
    }
    cout << '\n';
}

void solve() {
    int n;
    cin >> n;

    print_binary(n);

    // Builtin function in GCC
    // __builtin_popcountll, __builtin_ffsll, __builtin_clzll, __builtin_ctzll
    // Count set bits
    cout << "popcount: " << __builtin_popcount(n) << '\n';
    // Index of the lowest set bit
    cout << "ffs: " << __builtin_ffs(n) << '\n';
    // Count of leading zeros
    cout << "clz: " << __builtin_clz(n) << '\n';
    // Count of trailing zeros
    cout << "ctz: " << __builtin_ctz(n) << '\n';

    // Count set bits
    cout << "popcount: " << __popcount(n) << '\n';
    // Return bit lenght of n
    cout << "bit_width: " << __bit_width(n) << '\n';
    // Round down/up to the next power of two
    cout << "Round: " << __bit_floor(n) << ' ' << __bit_ceil(n) << '\n';
    // Rotate left/right
    cout << "Rotate: " << __rotl(n, 4) << ' ' << __rotr(n, 4) << '\n';
    // Count the leading/trailing zeros
    cout << "Count Zeros: " << __countl_zero(n) << ' ' << __countr_zero(n) << '\n';
    // Count the leading/trailing ones
    cout << "Count Ones: " <<  __countl_one(n) << ' ' << __countr_one(n) << '\n';
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
