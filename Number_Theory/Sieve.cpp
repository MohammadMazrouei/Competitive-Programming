#include <bits/stdc++.h>
using namespace std;

// Sieve of Eratosthenes, O(n*log(log(n)))
vector<bool> is_prime;
void sieve(int n) {
    is_prime.assign(n + 1, true); 
    is_prime[0] = is_prime[1] = false;

    for (int i = 4; i <= n; i += 2) {
        is_prime[i] = false;
    }
    for (int i = 3; i * i <= n; i += 2) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += 2 * i) {
                is_prime[j] = false;
            }
        }
    }
}

void solve() {
    const int N = 1e9;
    sieve(N);    
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
