#include <bits/stdc++.h>
using namespace std;

// Tire on Bits, O(n)
template <typename T>
struct Trie {
    int sz;
    vector<int> cnt_prefix, cnt_word;
    vector<array<int, 2>> nxt;
    const int B = numeric_limits<T>::digits - 1;

    Trie(int n) : sz(1) {
        cnt_prefix.assign(n, 0);
        cnt_word.assign(n, 0);
        nxt.assign(n, array<int, 2>());
    }

    void insert(const T &x) {
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

    void erase(const T &x) {
        int v = 0;
        for (int i = B; i >= 0; i--) {
            int bit = x >> i & 1;
            v = nxt[v][bit];
            cnt_prefix[v]--;
            assert(cnt_prefix[v] >= 0);
        }
        cnt_word[v]--;
        assert(cnt_word[v] >= 0);
    }

    int count_prefix(const T &x) {
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

    int count_word(const T &x) {
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

    T max_xor(const T &x) {
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
    int q;
    cin >> q;

    const int N = 1e6;
    Trie<int> trie(N);
    while (q--) {
        int t, x;
        cin >> t >> x;

        if (t == 1) {
            trie.insert(x);
        }
        else if (t == 2) {
            trie.erase(x);
        }
        else if (t == 3) {
            cout << trie.max_xor(x) << '\n';
        }
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
