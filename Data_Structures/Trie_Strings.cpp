#include <bits/stdc++.h>
using namespace std;

// Trie on Strings, O(n)
struct Trie {
    int sz;
    vector<int> cnt_prefix, cnt_word;
    vector<array<int, 26>> nxt;

    Trie(int n) : sz(1) {
        sz = 1;
        cnt_prefix.assign(n, 0);
        cnt_word.assign(n, 0);
        nxt.assign(n, array<int, 26>());
    }

    void insert(string &s) {
        int v = 0;
        for (auto ch : s) {
            int ind = ch - 'a';
            if (!nxt[v][ind]) {
                nxt[v][ind] = sz++;
            }
            v = nxt[v][ind];
            cnt_prefix[v]++;
        }
        cnt_word[v]++;
    }
    void erase(string &s) {
        int v = 0;
        for (auto ch : s) {
            int ind = ch - 'a';
            assert(nxt[v][ind]);
            v = nxt[v][ind];
            cnt_prefix[v]--;
        }
        cnt_word[v]--;
        assert(cnt_word[v] >= 0);
    }
    int count_word(string &s) {
        int v = 0;
        for (auto ch : s) {
            int ind = ch - 'a';
            if (!nxt[v][ind]) {
                return 0;
            }
            v = nxt[v][ind];
        }
        return cnt_word[v];
    }
    int count_prefix(string &s) {
        int v = 0;
        for (auto ch : s) {
            int ind = ch - 'a';
            if (!nxt[v][ind]) {
                return 0;
            }
            v = nxt[v][ind];
        }
        return cnt_prefix[v];
    }
};

void solve() {
    int q;
    cin >> q;

    const int N = 1e6;
    Trie trie(N);
    while (q--) {
        int t;
        cin >> t;

        string s;
        cin >> s;

        if (t == 1) {
            trie.insert(s);
        }
        else if (t == 2) {
            trie.erase(s);
        }
        else if (t == 3) {
            cout << trie.count_word(s) << '\n';
        }
        else if (t == 4) {
            cout << trie.count_prefix(s) << '\n';
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
