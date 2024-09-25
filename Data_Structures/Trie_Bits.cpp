#include <bits/stdc++.h>
using namespace std;

// Tire on Bits, O(n)
template <typename T>
struct Trie2 {
    const int B = numeric_limits<T>::digits;
    int sz;
    vector<int> cnt_prefix, cnt_word;
    vector<array<int, 2>> nxt;

    Trie2(int n) : sz(1) {
        cerr << B << endl;
        cnt_prefix.assign(n, 0);
        cnt_word.assign(n, 0);
        nxt.resize(n);
    }

    void insert(T x) {
        int v = 0;
        for (int i = B; i >= 0; i--) {
            int bit = x >> i & 1;
            if (!nxt[v][bit]) {
                nxt[v][bit] = sz++;
            }
            v = nxt[v][bit];
            cnt_prefix[v]++;
        }
        cnt_word[v]++;
    }
    void erase(int x) {
        int v = 0;
        for (int i = B; i >= 0; i--) {
            int bit = x >> i & 1;
            assert(nxt[v][bit]);
            v = nxt[v][bit];
            cnt_prefix[v]--;
        }
        cnt_word[v]--;
        assert(cnt_word[v] >= 0);
    }
    int count_word(T x) {
        int v = 0;
        for (int i = B; i >= 0; i--) {
            int bit = x >> i & 1;
            if (!nxt[v][bit]) {
                return 0;
            }
            v = nxt[v][bit];
        }
        return cnt_word[v];
    }
    int count_prefix(T x) {
        int v = 0;
        for (int i = B; i >= 0; i--) {
            int bit = x >> i & 1;
            if (!nxt[v][bit]) {
                return 0;
            }
            v = nxt[v][bit];
        }
        return cnt_prefix[v];
    }
    T max_xor(T x) {
        T res{};
        int v = 0;
        for (int i = B; i >= 0; i--) {
            int bit = x >> i & 1;
            if (cnt_prefix[nxt[v][bit ^ 1]]) {
                v = nxt[v][bit ^ 1];
                res += T(1) << i;
            }
            else {
                v = nxt[v][bit];
            }
        }
        return res;
    }
};

void solve() {
        
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
