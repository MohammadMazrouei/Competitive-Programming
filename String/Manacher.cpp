#include <bits/stdc++.h>
using namespace std;

// Find all sub-palindrome, O(n)
// m_even[i] = (m[2i] - 1) / 2, m_odd[i] = m[2i + 1] / 2
vector<int> manacher(const string &s) {
    string t = "#";
    for (auto c : s) {
        t += c;
        t += '#';
    }

    int n = t.size();
    vector<int> m(n);
    for (int i = 0, j = 0; i < n; i++) {
        if (2 * j - i >= 0 && j + m[j] > i) {
            m[i] = min(m[2 * j - i], j + m[j] - i);
        }
        while (i - m[i] >= 0 && i + m[i] < n && t[i - m[i]] == t[i + m[i]]) {
            m[i]++;
        }
        if (i + m[i] > j + m[j]) {
            j = i;
        }
    }
    return m;
}

void solve() {
    string s;
    cin >> s;

    vector<int> m = manacher(s);

    auto is_palindrome = [&](int l, int r) -> bool {
        int len = r - l + 1, mid = l + r + 1;
        int num = (m[mid] - (len % 2 == 0)) / 2;
        return (2 * num - len % 2) >= len;
    };

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;

        if (is_palindrome(l, r)) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
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
