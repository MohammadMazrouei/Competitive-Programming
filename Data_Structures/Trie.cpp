#include <bits/stdc++.h>
using namespace std;

// Trie on Strings, O(n)
struct Trie {
    struct Node {
        Node* links[26];
        int cnt_word = 0, cnt_prefix = 0;

        bool contain_key(char ch) {
            return links[ch - 'a'];
        }
        Node* get(char ch) {
            return links[ch - 'a'];
        }
        void put(char ch, Node* node) {
            links[ch - 'a'] = node;
        }
    };

    Node* root;

    Trie () {
        root = new Node();
    }
    Trie (vector<string> &a) {
        root = new Node();
        for (auto &s : a) {
            insert(s);
        }
    }

    void insert(string &s) {
        Node* node = root;
        for (auto ch : s) {
            if (!node->contain_key(ch)) {
                node->put(ch, new Node());
            }
            node = node->get(ch);
            node->cnt_prefix++;
        }
        node->cnt_word++;
    }
    void erase(string &s) {
        Node* node = root;
        for (auto ch : s) {
            assert(node->contain_key(ch));
            node = node->get(ch);
            node->cnt_prefix--;
        }
        node->cnt_word--;

    }
    int count_word(string &s) {
        Node* node = root;
        for (auto ch : s) {
            if (!node->contain_key(ch)) {
                return 0;
            }
            node = node->get(ch);
        }
        return node->cnt_word;
    }
    int count_prefix(string &s) {
        Node* node = root;
        for (auto ch : s) {
            if (!node->contain_key(ch)) {
                return 0;
            }
            node = node->get(ch);
        }
        return node->cnt_prefix;
    }
};

void solve() {
    int q;
    cin >> q;

    Trie trie;
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
